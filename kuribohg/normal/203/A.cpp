#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int x,t,a,b,da,db;
int main()
{
    scanf("%d%d%d%d%d%d",&x,&t,&a,&b,&da,&db);
    for(int i=0;i<t;i++)
        for(int j=0;j<t;j++)
            if(a+b-da*i-db*j==x) {puts("YES");return 0;}
    for(int i=0;i<t;i++)
        if(a-da*i==x||b-db*i==x) {puts("YES");return 0;}
    if(x==0)  {puts("YES");return 0;}
    puts("NO");
    return 0;
}