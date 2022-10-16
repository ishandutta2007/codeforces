#include<bits/stdc++.h>
 
using namespace std;
 
const int N=4005;
const int M=805;
 
int n,m,u[N][N],a[M],s1[N][N],cost[N][N],dp[N][M],opt[N][M];
 
template<typename T> inline void Cin(T &x)
{
    char c=getchar();
    x=0;
    while (c < '0' || c >'9')
        c = getchar();
    while (c>='0'&&c<='9')
        x=x*10+c-'0',c = getchar();
}
template <typename T, typename... Args> inline void Cin(T& a, Args&... args)
{
    Cin(a);
    Cin(args...);
}
 
void sol(int lev,int l,int r,int L,int R)
{
    if(l>r) return ;
    int mid=(l+r)/2;
    dp[mid][lev]=1e9;
    for(int i=L;i<=min(R,mid-1);i++)
    {
        long long cur=dp[i][lev-1]+cost[i+1][mid];
        if(dp[mid][lev]>cur)
        {
            opt[mid][lev]=i;
            dp[mid][lev]=cur;
        }
    }
    sol(lev,l,mid-1,L,opt[mid][lev]);
    sol(lev,mid+1,r,opt[mid][lev],R);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Cin(n,m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            Cin(u[i][j]);
            s1[i][j]=s1[i][j-1]+u[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        cost[i][i]=0;
        for(int j=i+1;j<=n;j++)
        {
            cost[i][j]=cost[i][j-1]+s1[j][j]-s1[j][i-1];
        }
    }
    for(int i=1;i<=n;i++) dp[i][1]=cost[1][i];
    for(int lev=2;lev<=m;lev++) sol(lev,1,n,0,n-1);
    cout<<dp[n][m];
}