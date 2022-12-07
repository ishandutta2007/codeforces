#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,Q,r1,c1,r2,c2;
int s[510][510];
char a[510][510];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]=='.'&&a[i-1][j]=='.') s[i][j]++;
            if(a[i][j]=='.'&&a[i][j-1]=='.') s[i][j]++;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            s[i][j]+=s[i-1][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            s[i][j]+=s[i][j-1];
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        int res=s[r2][c2]-s[r1-1][c2]-s[r2][c1-1]+s[r1-1][c1-1];
        for(int i=c1;i<=c2;i++)
            if(a[r1][i]=='.'&&a[r1-1][i]=='.') res--;
        for(int i=r1;i<=r2;i++)
            if(a[i][c1]=='.'&&a[i][c1-1]=='.') res--;
        printf("%d\n",res);
    }
    return 0;
}