#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,m;
char a[110][110];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]=='-') continue;
            if((i+j)&1) a[i][j]='W';
            else a[i][j]='B';
        }
    for(int i=1;i<=n;i++) printf("%s\n",a[i]+1);
    return 0;
}