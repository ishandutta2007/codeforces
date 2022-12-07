#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
char str[100];
int main()
{
    scanf("%d%*s%s",&n,str);
    if(str[0]=='w')
    {
        if(n==5) puts("53");
        else if(n==6) puts("53");
        else puts("52");
    }
    else
    {
        if(n<=29) puts("12");
        else if(n==30) puts("11");
        else if(n==31) puts("7");
    }
    return 0;
}