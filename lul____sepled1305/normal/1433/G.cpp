#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int N = 1e3+5;

int dp[N][N];
vector<pii> G[N];

struct Edge
{
    int a,b,c;

    Edge(int x, int y, int z)
    {
        a=x,b=y,c=z;
    }
};

int dijkstra(int src)
{
    for(int i=0;i<1005;i++)
        dp[src][i] = 1e9;

    priority_queue<pii,vector<pii>, greater<pii>> pq;
    dp[src][src] = 0;
    pq.push({0,src});
    while(!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();
        int v = cur.second;
        int d_v = cur.first;

        if(dp[src][v] != d_v)
            continue;

        for(auto it: G[v])
        {
            if(dp[src][it.first] > dp[src][v]+it.second)
            {
                dp[src][it.first] = dp[src][v]+it.second;
                pq.push({dp[src][it.first],it.first});
            }
        }
    }
}

int main()
{
    int n,m,k,i,j;
    vector<pii> courier;
    vector<Edge> mm;
    cin>>n>>m>>k;
    for(i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
        mm.push_back(Edge(a,b,c));
    }
    for(i=0;i<n;i++)
        dijkstra(i);

    for(i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        courier.push_back({a,b});
    }
    int mini = 1e9;
    for(i=0;i<m;i++)
    {
        int sum = 0;
        for(auto it: courier)
        {
            int can = 1e9;
            can = min(dp[it.first][it.second],can);
            can = min(dp[it.first][mm[i].a] + dp[mm[i].b][it.second],can);
            can = min(dp[mm[i].a][it.second] + dp[it.first][mm[i].b],can);
            sum+=can;
        }
        mini = min(mini,sum);
    }
    cout<<mini;
    return 0;
}