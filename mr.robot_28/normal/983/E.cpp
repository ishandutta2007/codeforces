#include<bits/stdc++.h>
using namespace std;
int n;
vector <vector <int> > g;
vector <int> tin, tout;
vector <vector <int> > up, up1;
int m;
vector <vector <int> > add, add1;
int t;
vector <int> ans;
vector <vector <pair <int, int> > > queries;
int timer = 0;
void dfs(int v)
{
    timer++;
    tin[v] = timer;
    for(int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        up[0][to] = v;
        for(int j = 1; j < t; j++)
        {
            up[j][to] = up[j - 1][up[j - 1][to]];
        }
        dfs(to);
    }
    tout[v] = timer;
}
bool pred(int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}
int lca(int a, int b)
{
    if(pred(a, b))
    {
        return a;
    }
    if(pred(b, a))
    {
        return b;
    }
    for(int j = t - 1; j >= 0; j--)
    {
        if(!pred(up[j][b], a))
        {
            b = up[j][b];
        }
    }
    return up[0][b];
}
void dfs1(int v)
{
    for(int j = 0; j< t; j++)
    {
        up1[j][v] = v;
    }
    int minup = v;
    for(int j = 0; j < g[v].size(); j++)
    {
        int to = g[v][j];
        dfs1(to);
        if(pred(up1[0][to], minup))
        {
            minup = up1[0][to];
        }
    }
    for(int j = 0; j < add1[v].size(); j++)
    {
        if(pred(add1[v][j], minup))
        {
            minup = add1[v][j];
        }
    }
    up1[0][v] = minup;
}
int jump(int a, int b)
{
    int ans = 0;
    for(int j = t - 1; j >= 0; j--)
    {
        if(!pred(up1[j][a], b))
        {
            ans += (1 << j);
            a = up1[j][a];
        }
    }
    if(!pred(up1[0][a], b))
    {
        return 1e9;
    }
    return ans + 1;
}
int jump1(int a, int b)
{
    for(int j = t - 1; j >= 0; j--)
    {
        if(!pred(up1[j][a], b))
        {
            a = up1[j][a];
        }
    }
    return a;
}
vector <int> tree;
void update(int v, int l, int r, int ind)
{
    tree[v]++;
    if(l == r)
    {
        return;
    }
    if(ind <= (r + l) / 2)
    {
        update(v * 2, l, (r + l) / 2, ind);
    }
    else
    {
        update(v * 2 + 1, (r + l) / 2 + 1, r, ind);
    }
}
int ans1(int v, int l, int r, int al, int ar)
{
    if(l >= al && r <= ar)
    {
        return tree[v];
    }
    else if(l <= ar && r >= al)
    {
        return ans1(v *2, l, (r + l) / 2, al, ar) + ans1(v * 2 + 1, (r + l)/ 2 + 1, r, al, ar);
    }
    return 0;
}
vector <bool> upd;
void dfs2(int v)
{
    vector <int> calc;
    for(int i = 0; i < queries[v].size(); i++)
    {
        int b = queries[v][i].first;
        int ind = queries[v][i].second;
        calc.push_back(ans1(1, 1, n, tin[b], tout[b]));
    }
    for(int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        dfs2(to);
    }
    for(int i = 0; i < add[v].size(); i++)
    {
        update(1, 1, n, tin[add[v][i]]);
    }
    for(int i = 0; i < queries[v].size(); i++)
    {
        int b = queries[v][i].first;
        int ind = queries[v][i].second;
        if(ans1(1, 1, n, tin[b], tout[b]) > calc[i])
        {
            upd[ind] = 1;
        }
    }
}
signed main()
{
//    ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
    //cout.tie(NULL);
    cin >> n;
    tree.resize(4 * n + 4);
    upd.resize(4 * n + 4);
    upd.resize(n);
    t = log2(n) + 1;
    g.resize(n);
    tin.resize(n);
    tout.resize(n);
    add.resize(n);
    queries.resize(n);
    up1.resize(t, vector <int> (n));
    up.resize(t, vector <int> (n));
    for(int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }
    for(int i = 0; i < t; i++)
    {
        up[i][0] = 0;
    }
    dfs(0);
    cin >> m;
    add.resize(n);
    add1.resize(n);
    upd.resize(m);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int v =lca(a, b);
        add1[b].push_back(v);
        add1[a].push_back(v);
        add[a].push_back(b);
        add[b].push_back(a);
    }
    dfs1(0);
    for(int j = 1; j < t; j++)
    {
        for(int i = 0; i < n; ++i)
        {
            up1[j][i] = up1[j - 1][up1[j - 1][i]];
        }
    }
    int q;
    cin >> q;
    ans.resize(q);
    for(int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int v = lca(a, b);
        if(pred(a, b))
        {
            ans[i] = jump(b, a);
        }
        else if(pred(b, a))
        {
            ans[i] = jump(a, b);
        }
        else
        {
            ans[i] = jump(a, v) + jump(b, v);
            a = jump1(a, v);
            b = jump1(b, v);
            queries[a].push_back({b, i});
            queries[b].push_back({a, i});
        }
    }
    dfs2(0);
    for(int i = 0; i < q; i++)
    {
        if(upd[i])
        {
            ans[i]--;
        }
        if(ans[i] >= 1e9)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << ans[i] << "\n";
        }
    }
    return 0;
}