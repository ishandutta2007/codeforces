#include<cstdio>
#include<cstring>
char s[100010];
int a[5][4]={{},{1},{1,2,4,3},{1,3,4,2},{1,4}},b;
int main()
{
    gets(s+1);
    int len=strlen(s+1);
    s[0]='0';
    b=(s[len]-'0')+(s[len-1]-'0')*10;
    printf("%d\n",(1+a[2][b%4]+a[3][b%4]+a[4][b%2])%5);
}