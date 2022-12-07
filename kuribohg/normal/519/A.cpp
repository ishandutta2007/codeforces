#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char str[1010][1010];
int w[100010],a,b;
int main()
{
    w['Q']=w['q']=9;
    w['R']=w['r']=5;
    w['B']=w['b']=3;
    w['N']=w['n']=3;
    w['P']=w['p']=1;
    for(int i=1;i<=8;i++)
        scanf("%s",str[i]+1);
    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
            if(str[i][j]>='A'&&str[i][j]<='Z') a+=w[str[i][j]];
            else b+=w[str[i][j]];
    if(a>b) puts("White");
    else if(b>a) puts("Black");
    else puts("Draw");
    return 0;
}