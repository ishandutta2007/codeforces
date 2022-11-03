#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
const int mod = 1e9 + 7;
vector<int> in[maxn] , out[maxn] , topol;
bool visited[maxn];
ll a , b , color[maxn] , c , l[maxn] , t[maxn] , _min[maxn] , ans;
ll res;
void dfs(int v)
{
    visited[v] = 1;
    for(auto u : out[v])
        if(!visited[u])
            dfs(u);
    topol.pb(v);
}
void sfd(int v)
{
    if(color[v] != -1)
        return;
    color[v] = c;
    if(l[v] < _min[c])
    {
        _min[c] = l[v];
        t[c] = 1;
    }
    else if(l[v] == _min[c])
        t[c]++;
    for(auto u : in[v])
        sfd(u);
}
int main()
{
    int n , m;
    scanf("%d", &n);
    fill(color , color + maxn , -1);
    fill(_min , _min + maxn , 1e9 + 1);
    for(int i = 0; i < n; i++)
        scanf("%d" , &l[i]);
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &a , &b);
        out[--a].pb(--b);
        in[b].pb(a);
    }
    for(int i = 0; i < n; i++)
        if(!visited[i])
            dfs(i);
    res = 1;
    for(int i = n - 1; i > -1; i--)
    {
        if(color[topol[i]] == -1)
            c++ , sfd(topol[i]) , res = (res * t[c]) % mod , ans += _min[c];
    }
    cout << ans << " " << res;
}