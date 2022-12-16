#include<bits/stdc++.h>
using namespace std;
const int nmax=3e2+42,SZ=nmax*2;
int n,m,p;
int arr[nmax][nmax];
int dp[nmax][nmax];
vector< pair<int,int> > seen[nmax*nmax];
vector< pair<int,int> > help[nmax*nmax];
int dist[nmax][nmax];
vector< pair<int,int> > bfs[SZ];
bool ok(int i_,int j_)
{
    return 1<=i_&&i_<=n&&1<=j_&&j_<=m;
}
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};
int main()
{
scanf("%i%i%i",&n,&m,&p);
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    dp[i][j]=1e9;

for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        scanf("%i",&arr[i][j]);
        if(arr[i][j]==1)dp[i][j]=i-1+j-1;
        seen[arr[i][j]].push_back({i,j});
    }

for(int i=1;i<p;i++)
{
    if(seen[i].size()*seen[i+1].size()<n*m)//brute force
    {
        for(int j=0;j<seen[i+1].size();j++)
            for(int k=0;k<seen[i].size();k++)
            dp[seen[i+1][j].first][seen[i+1][j].second]=min(dp[seen[i+1][j].first][seen[i+1][j].second],
                                                        dp[seen[i][k].first][seen[i][k].second]+abs(seen[i+1][j].first-seen[i][k].first)+abs(seen[i+1][j].second-seen[i][k].second));
    }
    else//bfs
    {
        int mini=1e9;
        for(auto k:seen[i])
            mini=min(mini,dp[k.first][k.second]);

        for(int j=1;j<=n;j++)
            for(int k=1;k<=m;k++)
            dist[j][k]=1e9;

        for(int j=0;j<SZ;j++)
            bfs[j].clear();

        for(auto k:seen[i])
            {
            bfs[dp[k.first][k.second]-mini].push_back(k);
            }

        for(int j=0;j<SZ;j++)
            for(auto k:bfs[j])
            {
            if(dist[k.first][k.second]<=j)continue;
            dist[k.first][k.second]=j;
                for(int t=0;t<4;t++)
                    if(ok(k.first+x[t],k.second+y[t]))
                        bfs[j+1].push_back({k.first+x[t],k.second+y[t]});
            }

        for(auto k:seen[i+1])
            dp[k.first][k.second]=dist[k.first][k.second]+mini;
    }
}

printf("%i\n",dp[seen[p][0].first][seen[p][0].second]);
return 0;
}