#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
vector<int> adj[maxn];
long double res[maxn];
ll t[maxn];
void dfs(int v , int p = -1)
{
    t[v] = 1;
    for(auto u : adj[v])
    {
        if(u == p)
            continue;
        dfs(u , v);
        t[v] += t[u];
    }
}
void adfs(int v , int p = -1)
{
    for(auto u : adj[v])
    {
        if(u == p)
            continue;
        res[u] = res[v] + (double)(t[v] - t[u] - 1) / 2 + 1;
        adfs(u , v);
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int a;
        cin >> a;
        a--;
        adj[i].pb(a);
        adj[a].pb(i);
    }
    res[0] = 1;
    dfs(0);
    adfs(0);
    cout << fixed << setprecision(1);
    for(int i = 0; i < n; i++)
        cout << res[i] << " ";
}