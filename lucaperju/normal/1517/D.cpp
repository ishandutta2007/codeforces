#include <bits/stdc++.h>
using namespace std;
int dp[11][505][505];
int dl[505][505],n,m;
int dc[505][505];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int cst (int i, int j, int a)
{
    int i1,j1;
    i1=i+dx[a];
    j1=j+dy[a];
    if(i1<=0 || j1<=0 || i1>n || j1>m)
        return 100000000;
    if(a==0)
        return dl[i][j];
    if(a==1)
        return dl[i][j-1];
    if(a==2)
        return dc[i][j];
    if(a==3)
        return dc[i-1][j];
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long i,j,k,cnt,t;
    cin>>n>>m>>k;
    for(i=1;i<=n;++i)
        for(j=1;j<m;++j)
            cin>>dl[i][j];
    for(i=1;i<n;++i)
        for(j=1;j<=m;++j)
            cin>>dc[i][j];
    if(k%2)
    {
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
                cout<<-1<<' ';
            cout<<'\n';
        }
        return 0;
    }
    k>>=1;
    for(int dst=1;dst<=k;++dst)
    {
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
            {
                dp[dst][i][j]=100000000;
                for(int dc=0;dc<=3;++dc)
                {
                    dp[dst][i][j]=min(dp[dst][i][j],dp[dst-1][i+dx[dc]][j+dy[dc]]+cst(i,j,dc));
                }
            }
        }
    }
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
        {
            cout<<2*dp[k][i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}