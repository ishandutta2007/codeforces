#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=3010;
const int MOD=1000000007;
int n,m;
LL f[MAXN][MAXN],ans1,ans2,ans3,ans4;
char a[MAXN][MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
    if(a[1][2]=='.') f[1][2]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(i==1&&j==2) continue;
            if(a[i][j]=='.') f[i][j]=(f[i-1][j]+f[i][j-1])%MOD;
        }
    ans1=f[n-1][m];
    memset(f,0,sizeof(f));
    if(a[2][1]=='.') f[2][1]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(i==2&&j==1) continue;
            if(a[i][j]=='.') f[i][j]=(f[i-1][j]+f[i][j-1])%MOD;
        }
    ans2=f[n][m-1];
    memset(f,0,sizeof(f));
    if(a[1][2]=='.') f[1][2]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(i==1&&j==2) continue;
            if(a[i][j]=='.') f[i][j]=(f[i-1][j]+f[i][j-1])%MOD;
        }
    ans3=f[n][m-1];
    memset(f,0,sizeof(f));
    if(a[2][1]=='.') f[2][1]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(i==2&&j==1) continue;
            if(a[i][j]=='.') f[i][j]=(f[i-1][j]+f[i][j-1])%MOD;
        }
    ans4=f[n-1][m];
    memset(f,0,sizeof(f));
    printf("%I64d\n",((ans1*ans2)%MOD-(ans3*ans4)%MOD+MOD)%MOD);
    return 0;
}