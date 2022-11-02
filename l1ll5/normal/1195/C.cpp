#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 300005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
ll p[3][N];
ll dp[N][3];

int main()
{
    n=read();
    for(int i=1;i<=2;i++)
    for(int j=1;j<=n;j++)p[i][j]=read();
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+p[1][i];
        dp[i][2]=max(dp[i-1][0],dp[i-1][1])+p[2][i];
    }
    printf("%lld\n",max(dp[n][0],max(dp[n][1],dp[n][2])));
}