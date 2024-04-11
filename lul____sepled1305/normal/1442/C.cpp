/** Congratulation to Joe Biden for presidential election **/
#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
using pii = pair<int,int>;
using piii = pair<pii,int>;
int N = 2e5+10;
const int M = 5e6+250;
const int L = 4e5+20;
const int INF = 1e9+10;
int dp[M];
vector<pii> G[M];
pii heavy[L];
vector<int> _G[L];
int n,m,i,j;
 
int plusi(int a, int b)
{
    return ((a+b)%mod);
}
 
int multi(int a,int b)
{
    long long ans = (1LL*a*b)%mod;
    return (int) ans;
}
 
int power(int base, int pow)
{
    if(pow == 0)
        return 1;
    if(pow == 1)
        return base;
 
    int get = power(base, pow/2);
    get = multi(get,get);
    if(pow%2 == 1)
        get = multi(get, base);
    return get;
}
 
struct Edge
{
    int from, to;
 
    Edge(int a, int b)
    {
        from = a;
        to = b;
    }
};
 
int convert(pii &a)
{
    int ans = power(2,a.first);
    return plusi(ans,a.second);
}
 
vector<Edge> edges;
 
int light_dijkstra()
{
    int i,j;
    for(i=0;i<20;i++)
    {
        for(j=0;j<n;j++)
        {
            pii GG = {(i+1)*N+j,power(2,i)};
            G[i*N+j].push_back(GG);
        }
    }
    for(i=0;i<21;i++)
    {
        for(auto it: edges)
        {
            if(i%2 == 0)
                G[i*N+it.from].push_back({i*N+it.to,1});
            else
                G[i*N+it.to].push_back({i*N+it.from,1});
        }
    }
    for(i=0;i<21*N;i++)
        dp[i] = INF;
 
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,0});
    dp[0] = 0;
    while(!pq.empty())
    {
        pii top = pq.top();
        pq.pop();
        int d_v = top.first;
        int v = top.second;
        if(dp[v] != d_v)
            continue;
 
        for(auto it: G[v])
        {
            if(dp[it.first] > d_v + it.second)
            {
                dp[it.first] = d_v + it.second;
                pq.push({dp[it.first],it.first});
            }
        }
    }
    int mini = INF;
    for(i=0;i<21;i++)
    {
        mini = min(mini,dp[i*N+n-1]);
    }
    return mini;
}
 
bool comp(pii &a, pii &b)
{
    if(a.first != b.first)
        return (a.first < b.first);
    return (a.second < b.second);
}
 
bool eq(pii &a, pii &b)
{
    return (a.first == b.first && a.second == b.second);
}
 
int heavy_dijkstra()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        _G[i].push_back(i+N);
        _G[i+N].push_back(i);
    }
    for(i=0;i<2*N;i++)
    {
        heavy[i] = {INF,INF};
    }
    for(auto it: edges)
    {
        _G[it.from].push_back(it.to);
        _G[it.to + N].push_back(it.from + N);
    }
 
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    pq.push({{0,0},0});
    heavy[0] = {0,0};
    while(!pq.empty())
    {
        piii cur = pq.top();
        pq.pop();
        pii d_v = cur.first;
        int v = cur.second;
        if(!eq(d_v,heavy[v]))
            continue;
 
        for(auto it: _G[v])
        {
            if(abs(it-v)!=N)
            {
                pii dist = {d_v.first,d_v.second+1};
                if(comp(dist,heavy[it]))
                {
                    heavy[it] = dist;
                    pq.push({dist,it});
                }
            }
            else
            {
                pii dist = {d_v.first+1,d_v.second};
                if(comp(dist,heavy[it]))
                {
                    heavy[it] = dist;
                    pq.push({dist,it});
                }
            }
        }
    }
    if(comp(heavy[n-1],heavy[N+n-1]))
    {
        return convert(heavy[n-1]);
    }
    return convert(heavy[N+n-1]);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        edges.push_back(Edge(a,b));
    }
    int ans = light_dijkstra();
    if(ans != INF)
        cout<<ans;
    else
        cout<<heavy_dijkstra()-1;
    return 0;
}