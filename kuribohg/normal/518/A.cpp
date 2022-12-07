#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int len;
char s[110],t[110];
int main()
{
    scanf("%s%s",s,t);
    len=strlen(s);
    s[len-1]++;
    for(int i=len-1;i>=0;i--)
        if(s[i]>'z') s[i]='a',s[i-1]++;
    for(int i=0;i<len;i++)
        if(s[i]!=t[i]) {puts(s);return 0;}
    puts("No such string");
    return 0;
}