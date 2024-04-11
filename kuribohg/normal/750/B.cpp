#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int d;
char s[50];
int x;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%s",&d,s);
        if((x==0||x==20000)&&(s[0]=='E'||s[0]=='W')) {puts("NO");return 0;}
        if(s[0]=='E'||s[0]=='W') continue;
        if(s[0]=='N'&&x-d<0) {puts("NO");return 0;}
        if(s[0]=='S'&&x+d>20000) {puts("NO");return 0;}
        if(s[0]=='N') x-=d;
        else if(s[0]=='S') x+=d;
    }
    if(x==0) puts("YES");
    else puts("NO");
    return 0;
}