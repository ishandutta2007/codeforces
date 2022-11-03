#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define X first
#define Y second
const int maxn = 2e5 + 20;
vector<int> adj[maxn] , cmp[maxn] , co , sc , tc;
vector<pair<int , int> > ans;
bool visited[maxn] , hide[maxn] , state[maxn];
ll x;
void dfs(int v)
{
    cmp[x].pb(v);
    visited[v] = 1;
    for(auto u : adj[v])
        if(!visited[u] && !hide[u])
            dfs(u) , ans.pb({v , u});
}
int main()
{
    int n , m , s , t , ds , dt;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a , b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cin >> s >> t >> ds >> dt;
    hide[s] = hide[t] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(visited[i] || hide[i])
            continue;
        dfs(i);
        x++;
        bool f1 , f2;
        f1 = f2 = 0;
        for(auto v : cmp[x - 1])
        {
            for(auto u : adj[v])
            {
                if(u == s)
                    f1 = 1;
                if(u == t)
                    f2 = 1;
            }
        }
        if(f1 && f2)
            co.pb(x - 1);
        else if(f1)
            sc.pb(x - 1) , ds--;
        else if(f2)
            tc.pb(x - 1) , dt--;
        else
        {
            cout << "No\n";
            return 0;
        }
    }
    if(ds < 1 || dt < 1)
    {
        cout << "No\n";
        return 0;
    }
    if(co.size() == 0)
    {
        bool f = 0;
        for(auto x : adj[s])
            if(x == t)
                f = 1;
        if(!f)
        {
            cout << "No\n";
            return 0;
        }
        cout << "Yes\n";
        cout << s << " " << t << endl;
    }
    if(!co.empty())
    if((int)(co.size()) - ds + 1 > dt)
    {
        cout << "No\n";
        return 0;
    }
    if(!co.empty())
    cout << "Yes\n";
    for(auto a : sc)
    {
        bool f = 0;
        for(auto v : cmp[a])
        {
            if(f)
                break;
            for(auto u : adj[v])
            {
                if(u == s)
                {
                    cout << v << " " << u << endl;
                    f = 1;
                    break;
                }
            }
        }
    }
    ll dds = ds;
    for(auto a : co)
    {
        if(!ds)
            break;
        bool f = 0;
        for(auto v : cmp[a])
        {
            if(f)
                break;
            for(auto u : adj[v])
            {
                if(u == s)
                {
                    cout << v << " " << u << endl;
                    f = 1;
                    break;
                }
            }
        }
        ds--;
    }
    for(int i = min(dds , (ll)co.size()) - 1; i < co.size(); i++)
    {
        int a = co[i];
        bool f = 0;
        for(auto v : cmp[a])
        {
            if(f)
                break;
            for(auto u : adj[v])
            {
                if(u == t)
                {
                    cout << v << " " << u << endl;
                    f = 1;
                    break;
                }
            }
        }
    }
    for(auto a : tc)
    {
        bool f = 0;
        for(auto v : cmp[a])
        {
            if(f)
                break;
            for(auto u : adj[v])
            {
                if(u == t)
                {
                    cout << v << " " << u << endl;
                    f = 1;
                    break;
                }
            }
        }
    }
    for(auto e : ans)
        cout << e.first << " " << e.second << endl;
}