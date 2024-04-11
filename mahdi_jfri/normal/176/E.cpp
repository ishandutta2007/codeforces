#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
const int maxbit = 40;
vector<pair<int , int> > adj[maxn];
set<int> s;
map<int , int> mp;
ll p[maxn][maxbit] , t = -1 , st[maxn], ft[maxn] , res , dist[maxn];
void dfs(int v , int p1 = -1)
{
    if(p1 != -1)
        p[v][0] = p1;
    if(p1 != -1)
    for(int i = 1; i < maxbit; i++)
    {
        p[v][i] = p[p[v][i - 1]][i - 1];
    }
    st[v] = ++t;
    mp[t] = v;
    for(auto u : adj[v])
    {
        if(u.first == p1)
            continue;
       // p[u.first][0] = v;
       // cout << p[u.first][0] << " ";
        //for(int i = 1; i < maxbit; i++)
          //  p[u.first][i] = p[p[v][i - 1]][i - 1] , cout << u.first + 1 << " " << i << " " << p[u.first][i] << endl;
        dist[u.first] = dist[v] + u.second;
        dfs(u.first , v);
    }
    ft[v] = t;
}
bool is_par(int v,int u)
{
    if(st[v] <= st[u] && ft[v] >= ft[u])
        return 1;
    return 0;
}
int lca(int v, int u)
{
    for(int h = maxbit - 1; h >= 0; h--)
        if(!(is_par(p[v][h] , u)))
        {
            v = p[v][h];
     //       cout << v << " ";
        }
    if(is_par(v , u))
        return v;
    return p[v][0];
}
ll d(int v , int u)
{
    return dist[v] - dist[lca(v , u)] * 2 + dist[u];
}
void change(int a)
{
    if(s.find(st[a]) != s.end())
    {
        set<int>::iterator it = s.find(st[a]);
        int u;
        if(it == s.begin())
        {
            u = *s.rbegin();
        }
        else
        {
            it--;
            u = *it;
            it++;
        }
        u = mp[u];
        res -= d(a , u);
        int u1;
        if(*it != *s.rbegin())
        {
            it++;
            u1 = *it;
            it--;
        }
        else
        {
            u1 = *s.begin();
        }
        u1 = mp[u1];
        res -= d(a , u1);
        res += d(u , u1);
        s.erase(st[a]);
        return;
    }
    else
    {
        s.insert(st[a]);
        set<int>::iterator it = s.find(st[a]);
        int u;
        if(it == s.begin())
        {
            u = *s.rbegin();
        }
        else
        {
            it--;
            u = *it;
            it++;
        }
        u = mp[u];
        res += d(a , u);
        int u1;
        if(*it != *s.rbegin())
        {
            it++;
            u1 = *it;
            it--;
        }
        else
        {
            u1 = *s.begin();
        }
        u1 = mp[u1];
        res += d(a , u1);
        res -= d(u , u1);
  //      cout << "PASHM " << a + 1 << " " << u + 1 << " " << u1 + 1 << " " << lca(a , u) << endl;
  //      cout << d(a , u) << " " << d(a , u1) << " " << d(u , u1) << endl;
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int a , b , c;
        cin >> a >> b >> c;
        adj[--a].pb({--b , c});
        adj[b].pb({a , c});
    }
    dfs(0);
    int q;
    cin >> q;
    while(q--)
    {
        char ch;
        cin >> ch;
        if(ch == '?')
        {
            cout << res / 2 << endl;
            continue;
        }
        int a;
        cin >> a;
        a--;
        change(a);
    }
}