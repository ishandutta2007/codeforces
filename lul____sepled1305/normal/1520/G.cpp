#include<bits/stdc++.h>
#define ll long long
using namespace std;
using pll = pair<ll,ll>;
using pii = pair<int,int>;
using plii = pair<ll,pii>;
const ll INF = 1e18;
int m,n,w;
 
void dijkstra(int x, int y, vector<ll> dp[], vector<ll> b[])
{
    queue<plii> pq;
    pq.push({0,{x,y}});
    while(!pq.empty())
    {
        plii cur = pq.front();
        pq.pop();
        x = cur.second.first, y = cur.second.second;
        ll val = cur.first;
        if(dp[x][y] != INF)
            continue;
 
        dp[x][y] = val;
 
        if(x != 0 && b[x-1][y] != -1 && dp[x-1][y] == INF)
            pq.push({val+w,{x-1,y}});
        if(x != n-1 && b[x+1][y] != -1 && dp[x+1][y] == INF)
            pq.push({val+w,{x+1,y}});
        if(y != 0 && b[x][y-1] != -1 && dp[x][y-1] == INF)
            pq.push({val+w,{x,y-1}});
        if(y != m-1 && b[x][y+1] != -1 && dp[x][y+1] == INF)
            pq.push({val+w,{x,y+1}});
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin>>n>>m>>w;
    vector<ll> dp[n],ds[n],b[n];
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<m;i++)
        {
            int a;
            cin>>a;
            b[j].push_back(a);
            dp[j].push_back(INF);
            ds[j].push_back(INF);
        }
    }
    dijkstra(0,0,dp,b);
    dijkstra(n-1,m-1,ds,b);
    ll mi = INF, ma = INF;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(b[i][j] > 0)
            {
                mi = min(dp[i][j]+b[i][j],mi);
                ma = min(ds[i][j]+b[i][j],ma);
            }
        }
    }
    if(dp[n-1][m-1] == INF && (mi == INF || ma == INF))
        cout<<-1;
    else
        cout<<min(mi+ma,dp[n-1][m-1]);
    return 0;
}