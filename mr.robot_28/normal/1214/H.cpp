#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 4e5 + 100;
const int mod = 1e9 + 7;
int n, k;
int maxh[N];
vector <int> g[N];
void dfs(int v, int p = -1)
{
    for(auto to : g[v])
    {
        if(to == p)
        {
            continue;
        }
        dfs(to, v);
        maxh[v] = max(maxh[v], maxh[to] + 1);
    }
}
void dfs1(int v, int h1, int p = -1)
{
    vector <int> pref(sz(g[v]) + 1, -1e9), suf(sz(g[v]) + 1, -1e9);
    int a = h1, b = 0, c = 0;
    for(int i = 0; i < sz(g[v]); i++)
    {
        int to = g[v][i];
        if(to != p)
        {
            pref[i + 1] = maxh[to] + 1;
            if(maxh[to] + 1 > a){
                c = b;
                b = a;
                a = maxh[to] + 1;
            }
            else if(maxh[to] + 1 > b)
            {
                c = b;
                b = maxh[to] + 1;
            }
            else if(maxh[to] + 1 > c)
            {
                c = maxh[to] + 1;
            }
        }
        pref[i + 1] = max(pref[i + 1], pref[i]);
    }
    if(c > 0 && a + b >= k - 1 && b + c >= k - 1 && a + c >= k - 1)
    {
        cout << "No";
        exit(0);
    }
    for(int i = sz(g[v]) - 1; i >= 0; i--)
    {
        int to = g[v][i];
        if(to != p)
        {
            suf[i] = maxh[to] + 1;
        }
        suf[i] = max(suf[i], suf[i + 1]);
    }
    for(int i = 0; i < sz(g[v]); i++)
    {
        int to = g[v][i];
        if(to != p)
        {
            dfs1(to, max(pref[i], max(suf[i + 1], h1)) + 1, v);
        }
    }
}
int p[N];
int h[N];
int bfs(int v)
{
    for(int i = 0; i < n; i++)
    {
        h[i] = 1e9;
        p[i] = -1;
    }
    h[v] = 0;
    queue <int> q;
    q.push(v);
    int ans = 0;
    while(sz(q))
    {
        int a = q.front();
        q.pop();
        ans = a;
        for(auto to : g[a])
        {
            if(h[to] ==1e9)
            {
                h[to] = h[a] + 1;
                p[to] = a;
                q.push(to);
            }
        }
    }
    return ans;
}
int color[N];
void dfs_down(int v, int param)
{
    for(auto to : g[v])
    {
        if(!color[to])
        {
            color[to] = color[v] + param;
            if(color[to] == k + 1)
            {
                color[to] = 1;
            }
            else if(color[to] == 0)
            {
                color[to] = k;
            }
            dfs_down(to, param);
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    fill(color, color + N, 0);
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(k != 2)
    {
    dfs(0);
    dfs1(0, 0);
    }
    int v = bfs(0);
    int v1 = bfs(v);
   // cout << v << " " << v1 << "\n";
    vector <int> vec;
    while(v1 != -1)
    {
        vec.push_back(v1);
        v1 = p[v1];
    }
    reverse(vec.begin(), vec.end());
    for(int i = 0; i < sz(vec); i++)
    {
     //   cout << vec[i] << " ";
        color[vec[i]] = i % k + 1;
    }
   // cout << "\n";
    for(int i = 0; i < sz(vec) / 2; i++)
    {
        dfs_down(vec[i], -1);
    }
    for(int i = sz(vec) / 2; i < sz(vec); i++)
    {
        dfs_down(vec[i], 1);
    }
    cout << "Yes\n";
    for(int i = 0; i < n; i++)
    {
        cout << color[i] << " ";
    }
    return 0;
}