#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 100;

signed main()
{
 //   ifstream cin("input1.txt.4c");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> cnt(n);
    vector <vector <int> > g(n);
    vector <int> p(n);
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
    }
    vector <int> nxt(n, -1), pred(n, -1);
    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if(nxt[x] != y && nxt[x] != -1)
        {
            cout << 0;
            return 0;
        }
        if(pred[y] != x && pred[y] != -1)
        {
            cout << 0;
            return 0;
        }
        nxt[x] = y;
        pred[y] = x;
    }
    vector <int> col(n);
    vector <vector <int> > mass;
    for(int i = 0; i < n; i++)
    {
        if(pred[i] == -1)
        {
            vector <int> t;
            int u = i;
            while(u != -1)
            {
                col[u] = sz(mass);
                t.push_back(u);
                u = nxt[u];
            }
            mass.push_back(t);
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(p[i] != -1 && col[p[i]] != col[i])
        {
            cnt[col[i]]++;
            //cout << col[p[i]] << " " << col[i] << "\n";
            g[col[p[i]]].push_back(col[i]);
        }
    }
    queue <int> q;
    for(int i = 0; i < sz(mass); i++)
    {
        if(cnt[i] == 0)
        {
            q.push(i);
        }
    }
    vector <int> res;
    while(sz(q) != 0)
    {
        int v = q.front();
        q.pop();
        for(int i = 0; i < sz(mass[v]); i++)
        {
            res.push_back(mass[v][i]);
        }
        for(auto to : g[v])
        {
            cnt[to]--;
            if(cnt[to] == 0)
            {
                q.push(to);
            }
        }
    }
    if(sz(res) != n)
    {
        cout << 0;
        return 0;
    }
    vector <bool> used(n);
    for(auto v : res)
    {
        if(p[v] != -1 && !used[p[v]])
        {
            cout << 0;
            return 0;
        }
        used[v] = 1;
    }
    for(auto v : res)
    {
        cout << v + 1 << " ";
    }
    return 0;
}