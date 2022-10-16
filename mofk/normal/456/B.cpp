#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
    char n[100005],c[5];
    int i;
    scanf("%s",&n);
    if(strlen(n)==1)
    {
        if(n[0]=='0'||n[0]=='4'||n[0]=='8') printf("4");
        else printf("0");
    }
    else {
        c[0]=n[strlen(n)-2];
        c[1]=n[strlen(n)-1];
        i=atoi(c);
        if(i%4==0) printf("4");
        else printf("0");
    }
}