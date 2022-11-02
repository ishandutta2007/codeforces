#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
using pii = pair<int,int>;
long long dp[N][2][2];
vector<pii> G[N];
 
struct state
{
    long long w;
    int nd;
    bool a,b;
 
    state(long long w, int nd, bool a, bool b)
    {
        this->w = w;
        this -> nd = nd;
        this->a = a;
        this->b = b;
    }
 
};
 
struct comp{
    bool operator()(state &x, state &y)
    {
        return (x.w >= y.w);
    }
};
 
void dijkstra(int root)
{
    int i,j,k;
    for(i=0;i<N;i++)
        for(j=0;j<2;j++)
            for(k=0;k<2;k++)
                dp[i][j][k] = 1e18;
    for(j=0;j<2;j++)
        for(k=0;k<2;k++)
        if(j == k)
            dp[root][j][k] = 0;
    priority_queue<state,vector<state>,comp> pq;
    pq.push(state(0,root,0,0));
    pq.push(state(0,root,1,1));
    while(!pq.empty())
    {
        state cur = pq.top();
        pq.pop();
        if(dp[cur.nd][cur.a][cur.b] < cur.w)
            continue;
        for(auto it: G[cur.nd])
        {
            if(cur.a)
            {
                if(cur.b)
                {
                    if(dp[it.first][1][1] > cur.w + it.second)
                    {
                        dp[it.first][1][1] = cur.w + it.second;
                        pq.push(state(dp[it.first][1][1],it.first,1,1));
                    }
                }
                else
                {
                    if(dp[it.first][1][0] > cur.w + it.second)
                    {
                        dp[it.first][1][0] = cur.w + it.second;
                        pq.push(state(dp[it.first][1][0],it.first,1,0));
                    }
                    if(dp[it.first][1][1] > cur.w)
                    {
                        dp[it.first][1][1] = cur.w;
                        pq.push(state(dp[it.first][1][1],it.first,1,1));
                    }
                }
            }
            else
            {
                if(cur.b)
                {
                    if(dp[it.first][1][1] > cur.w + 2*it.second)
                    {
                        dp[it.first][1][1] = cur.w + 2*it.second;
                        pq.push(state(dp[it.first][1][1],it.first,1,1));
                    }
                    if(dp[it.first][0][1] > cur.w + it.second)
                    {
                        dp[it.first][0][1] = cur.w + it.second;
                        pq.push(state(dp[it.first][0][1],it.first,0,1));
                    }
                }
                else
                {
                    if(dp[it.first][1][0] > cur.w + 2*it.second)
                    {
                        dp[it.first][1][0] = cur.w + 2*it.second;
                        pq.push(state(dp[it.first][1][0],it.first,1,0));
                    }
                    if(dp[it.first][0][0] > cur.w + it.second)
                    {
                        dp[it.first][0][0] = cur.w + it.second;
                        pq.push(state(dp[it.first][0][0],it.first,0,0));
                    }
                    if(dp[it.first][0][1] > cur.w)
                    {
                        dp[it.first][0][1] = cur.w;
                        pq.push(state(dp[it.first][0][1],it.first,0,1));
                    }
                }
            }
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m,i;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    dijkstra(0);
    for(i=0;i<n-1;i++)
        cout<<dp[i+1][1][1]<<' ';
    return 0;
}