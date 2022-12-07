#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
char str[10];
int main()
{
    scanf("%d%d",&n,&m);
    bool ok=true;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%s",str);
            if(str[0]!='B'&&str[0]!='W'&&str[0]!='G') ok=false;
        }
    if(ok) puts("#Black&White");
    else puts("#Color");
    return 0;
}