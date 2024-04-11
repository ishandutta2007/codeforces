#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 4005
#define K 805
#define ll long long
using namespace std;
char xB[1<<15],*xS=xB,*xT=xB;
#define getchar() (xS==xT&&(xT=(xS=xB)+fread(xB,1,1<<15,stdin),xS==xT)?0:*xS++)
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,k;
int A[N][N],sum[N][N];
int dp[K][N];//j i
void solve(int x,int l,int r,int L,int R)
{
    if(l>r)return ;
    int mid=(l+r)>>1;
    int pos=0;
    for(int i=L;i<=R;i++)
    {
        if(dp[x-1][i]+sum[i+1][mid]<dp[x][mid])
        dp[x][mid]=dp[x-1][i]+sum[i+1][mid],pos=i;
    }
    if(l!=r)solve(x,l,mid,L,pos),solve(x,mid+1,r,pos,R);
}
int main()
{
    n=read(),k=read();
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)A[i][j]=A[i][j-1]+read();
    for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)sum[i][j]=sum[i][j-1]+A[j][j]-A[j][i-1];
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++)dp[1][i]=sum[1][i];
    for(int i=2;i<=k;i++)solve(i,1,n,1,n);
    printf("%d\n",dp[k][n]);
}