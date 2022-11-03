#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define int ll
const int maxn = 1e5 + 20;
const ll inf = 9e18;
vector<pair<int , int> >adj[maxn];

int d[maxn] , a , b, c , p[maxn] , visited[maxn];

set<pair<ll , int> > st;

void dij(int src)
{
    fill(d , d + maxn , inf);
    d[src] = 0;
    st.insert({0 , src});
    visited[src] = 1;
    while(!st.empty())
    {
        int v = st.begin() -> second;
        int w = st.begin() -> first;
        st.erase(st.begin());
        if(w != d[v])
            continue;
        for(int i = 0; i < adj[v].size(); i++)
        {
            pair<ll , int> e = adj[v][i];
            visited[e.first] = 1;
            if(d[e.first] > d[v] + e.second)
            {
                p[e.first] = v;
                d[e.first] = d[v] + e.second;
                st.insert({d[e.first], e.first});
            }
        }
    }
}
main()
{
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[--a].pb({--b , c});
        adj[b].pb({a , c});
    }
    fill(p , p + maxn , -1);
    dij(0);
    stack<int>st;
    st.push(n - 1);
    int x = p[n - 1];
    if(x == -1)
    {
        cout << -1;
        return 0;
    }
    while(x != -1)
    {
        st.push(x);
        x = p[x];
    }
    while(!st.empty())
        cout << st.top() + 1 << " ", st.pop();
}