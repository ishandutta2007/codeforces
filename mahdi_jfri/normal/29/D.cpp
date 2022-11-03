#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
typedef vector<int> vi;
const int maxn = 3e2 + 20;
const int maxlog = 9;
vi adj[maxn] , ans;
int l[maxn] , st[maxn] , en[maxn] , t , pr[maxlog][maxn] , visited[maxn * maxn] , tah = 1;
map<pair<int , int> , int> mp;
void lcadfs(int v, int p)
{
    pr[0][v] = p;
    for(int h = 1; h < maxlog; h++)
        pr[h][v] = pr[h - 1][pr[h - 1][v]];
    st[v] = t++;
    for(auto u : adj[v])
    {
        if(u != p)
        {
            lcadfs(u, v);
        }
    }
    en[v] = t;
}
bool is_par(int v,int u)
{
    if(st[v] <= st[u] && en[v] >= en[u])
        return 1;
    return 0;
}
int lca(int v, int u)
{
    for(int h = maxlog - 1; h >= 0; h--)
    {
        if(!(is_par(pr[h][v] , u)))
            v = pr[h][v];
    }
    if(is_par(v, u) == 1)
        return v;
    return pr[0][v];
}
void go(int v , int u)
{
    if(v == u)
    {
        ans.pb(u);
        return;
    }
    int x = lca(v , u);
    if(x == v)
    {
        ans.pb(x);
        for(auto y : adj[v])
            if(y != pr[0][v] && is_par(y , u))
            {
                visited[mp[{y , v}]]++;
                go(y , u);
                return;
            }
    }
    if(x == u)
    {
        stack<int> st;
        st.push(u);
        while(1)
        {
            if(st.top() == v)
                break;
            for(auto y : adj[st.top()])
                if(is_par(y , v) && y != pr[0][st.top()])
                {
                    visited[mp[{y , st.top()}]]++;
                    st.push(y);
                    break;
                }
        }
        while(!st.empty())
            ans.pb(st.top()) , st.pop();
        return;
    }
    ans.pb(v);
    go(v , x);
    go(x , u);
}
int main()
{
    int n , k = 0;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int a , b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
        mp[{a , b}] = i;
        mp[{b , a}] = i;
    }
    for(int i = 1; i < n; i++)
        if(adj[i].size() == 1)
            k++;
    for(int i = 0; i < k; i++)
        cin >> l[i] , l[i]--;
    lcadfs(0 , 0);
    for(int i = 0; i < k; i++)
        go(l[i - 1] , l[i]);
    go(l[k - 1] , 0);
    for(int i = 0; i < n - 1; i++)
        if(visited[i] != 2)
        {
            cout << -1 << endl;
            return 0;
        }
    cout << 1 << " ";
    for(int i = 0; i < ans.size(); i++)
        if(i > 0 && ans[i] != ans[i - 1])
            cout << ans[i] + 1 << " ";
}