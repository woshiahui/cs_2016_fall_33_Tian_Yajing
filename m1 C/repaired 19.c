#include <stdio.h>  
  
int state;  
  
int c1,c2;  
  
void change_state(int c);  
  
int main(int argc, const char * argv[]) {  
    int c;  
    state = 0;  
    c1 = 0;  
    c2 = 0;  
    while ((c=getchar())!=EOF) {  
        c1 = c2;  
        c2 = c;  
        change_state(c);  
    }  
    if (/* DISABLES CODE */ (0)==1) {  
        printf("just test://abcd");  
        printf("just test:/*hello*/");  
    }  
}  
  
/*״̬������*/  
void change_state(int c){  
    if (state==0) {//��ͨ״̬  
        if (c=='/') {  
            state = 1;  
        }else if (c=='"'){  
            state = 5;  
            putchar(c);  
        }else if (c=='\''){  
            state = 6;  
            putchar(c);  
        }  
        else{  
            state = 0;  
            putchar(c);  
        }  
    }else if (state==1) {//��⵽1��'/'  
        if (c=='/') {  
            state = 2;  
        }else if (c=='*'){  
            state = 3;  
        }else{  
            state = 0;  
            putchar(c1);  
            putchar(c);  
        }  
    }else if (state==2) {// "//"ע��״̬  
        if (c=='\n') {  
            state = 0;  
            putchar(c);  
        }else{  
            state = 2;  
        }  
    }else if (state==3) {// "/*"ע��״̬  
        if (c=='*') {  
            state = 4;  
        }else{  
            state = 3;  
        }  
    }else if (state==4) {  
        if (c=='/') {  
            state = 0;  
        }else{  
            state = 3;  
        }  
    }else if (state==5){//��"�ַ�����  
        if (c=='"') {  
            state = 0;  
            putchar(c);  
        }else if(c=='\\'){  
            state = 7;  
            putchar(c);  
        }else{  
            state = 5;  
            putchar(c);  
        }  
    }else if (state==6){//��'�ַ���  
        if (c=='\'') {  
            state = 0;  
            putchar(c);  
        }else if(c=='\\'){  
            state = 8;  
            putchar(c);  
        }else{  
            state = 6;  
            putchar(c);  
        }  
    }else if (state==7){//��"�ַ������"\"  
        state = 5;  
        putchar(c);  
    }else if (state==8){//��'�ַ������"\"  
        state = 6;  
        putchar(c);  
    }  
}  
