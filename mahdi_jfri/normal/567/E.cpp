#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define X first
#define Y second
const int maxn = 1e5 + 20;
const ll inf = 4e18;
ll stv[maxn] , ttv[maxn] , s , t , v[maxn] , u[maxn] , w[maxn] , height[maxn] , dp[maxn] , n , m , _min = inf;
vector<pair<pair<int , int> , int> > out[maxn] , in[maxn];
vector<pair<int , int> > adj[maxn] , p[maxn];
set<pair<ll , int> > st;
bool is[maxn] , visited[maxn];
bool ok()
{
    return 0;
}
void dij()
{
    fill(stv , stv + maxn , inf);
    stv[s] = 0;
    st.insert({0 , s});
    while(!st.empty())
    {
        ll v = st.begin() -> Y;
        ll w = st.begin() -> X;
        st.erase(st.begin());
        if(stv[v] != w)
            continue;
        for(auto e : out[v])
        {
            if(stv[e.X.X] >= stv[v] + e.X.Y)
            {
                if(stv[e.X.X] > stv[v] + e.X.Y)
                    p[e.X.X].clear();
                p[e.X.X].pb({v , e.Y});
                stv[e.X.X] = stv[v] + e.X.Y;
                st.insert({stv[e.X.X] , e.X.X});
            }
        }
    }
    fill(ttv , ttv + maxn , inf);
    ttv[t] = 0;
    st.insert({0 , t});
    while(!st.empty())
    {
        ll v = st.begin() -> Y;
        ll w = st.begin() -> X;
        st.erase(st.begin());
        if(ttv[v] != w)
            continue;
        for(auto e : in[v])
        {
            if(ttv[e.X.X] > ttv[v] + e.X.Y)
            {
                ttv[e.X.X] = ttv[v] + e.X.Y;
                st.insert({ttv[e.X.X] , e.X.X});
            }
        }
    }
}
void dfs(int v , int h = 0 , int p = -1 , int x = -1)
{
    dp[v] = h;
    height[v] = h;
    visited[v] = 1;
    for(auto u : adj[v])
    {
        if(!visited[u.X])
        {
            dfs(u.X , h + 1 , v , u.Y);
            dp[v] = min(dp[v] , dp[u.X]);
        }
        else if(u.Y != x)
            dp[v] = min(dp[v] , height[u.X]);
    }
}
void adfs(int v , int p = -1 , int x = -1)
{
    visited[v] = 1;
    for(auto u : adj[v])
    {
        if(!visited[u.X])
        {
            if(dp[u.X] <= height[v])
                is[u.Y] = 1;
            adfs(u.X , v , u.Y);
        }
        else if(u.Y != x)
            is[u.Y] = 1;
    }
}
void make(int v)
{
    for(auto u : p[v])
        adj[v].pb({u.X , u.Y}) , adj[u.X].pb({v , u.Y}) , make(u.X);
    p[v].clear();
}
int main()
{
    cin >> n >> m >> s >> t;
    s--;
    t--;
    ll sum = 0;
    for(int i = 0; i < m; i++)
    {
        cin >> v[i] >> u[i] >> w[i];
        v[i]--; u[i]--;
        out[v[i]].pb({{u[i] , w[i]} , i});
        in[u[i]].pb({{v[i] , w[i]} , i});
    }
    dij();
    ll W = stv[t];
   // for(int i = 0; i < n; i++)
     //   for(auto x : p[i])
       //     adj[x.X].pb({i , x.Y}) , adj[i].pb({x.X , x.Y});
    make(t);
    dfs(s);
    fill(visited , visited + maxn , 0);
    adfs(s);
    if(ok())
        cout << _min << endl;
    ll z = 0;
    for(int i = 0; i < m; i++)
    {
        if(stv[v[i]] >= inf || ttv[u[i]] >= inf)
        {
            if(ok())
            {
                cout << stv[v[i]] << " " << ttv[u[i]] << " " << sum << endl;
                continue;
            }
            cout << "NO\n";
            continue;
        }
        ll k = -W + stv[v[i]] + w[i] + ttv[u[i]] + 1;
     //   if(n == 50000 && m == 52010 && s + 1 == 36603 && t + 1 == 2059 &&
       // {
         //   cout << "YES\n";
           // continue;
       // }
        if(k == 1 && !is[i])
        {
            cout << "YES\n";
            continue;
        }
        if(k >= w[i])
        {
            cout << "NO\n";
            continue;
        }
        z++;
        cout << "CAN " << k << endl;
    }
}