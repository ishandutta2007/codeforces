#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 3e5 + 100;
const int mod = 1e9 + 7;
vector <pair <int, int> > g[N];
int dsu[N], rang[N], used[N];
const int T = 20;
int up[T][N];
int pred(int a)
{
    return a == dsu[a] ? a : dsu[a] = pred(dsu[a]);
}
void unite(int a, int b)
{
    a = pred(a);
    b = pred(b);
    if(rang[a] > rang[b])
    {
        swap(a, b);
    }
    dsu[a] = b;
    rang[b] += rang[a];
}
int _sz[N], pred_tree[N];
int val[N];
int timer = 0;
int tin[N], tout[N];
void dfs(int v, int p = -1)
{
    used[v] = 1;
    _sz[v] = 1;
    tin[v] = timer++;
    for(auto to : g[v])
    {
        if(to.X == p)
        {
            continue;
        }
        up[0][to.X] = v;
        val[to.X] = val[v] ^ to.Y;
        pred_tree[to.X] = v;
        dfs(to.X, v);
        _sz[v] += _sz[to.X];
    }
    tout[v] = timer++;
}
int mass[N];
int idx[N], st[N], en[N];
int Tree[4 * N], Tree_push[4 * N];
int it = 0, it1 = 0;
void dfs1(int v, int p = -1)
{
    int maxv = -1;
    for(auto to : g[v])
    {
        if(to.X == p)
        {
            continue;
        }
        if(maxv == -1 || _sz[to.X] > _sz[maxv])
        {
            maxv = to.X;
        }
    }
    if(maxv != -1)
    {
        idx[maxv] = it;
        mass[it++] = maxv;
        st[maxv] = st[v];
        dfs1(maxv, v);
    }
    for(auto to : g[v])
    {
        if(to.X == p || maxv == to.X)
        {
            continue;
        }
        idx[to.X] = it;
        st[to.X] = it;
        mass[it++] = to.X;
        dfs1(to.X, v);
    }
}
bool pr(int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}
void push(int v)
{
    Tree[v * 2] |= Tree_push[v];
    Tree[v * 2 + 1] |= Tree_push[v];
    Tree_push[v * 2] |= Tree_push[v];
    Tree_push[v * 2 + 1] |= Tree_push[v];
}
int ask(int v, int l, int r, int al, int ar)
{
    if(l >= al && r <= ar)
    {
        return Tree[v];
    }
    if(l <= ar && r >= al)
    {
        push(v);
        return ask(v * 2, l, (r + l) / 2, al, ar) + ask(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
    }
    return 0;
}
void update(int v, int l, int r, int al, int ar)
{
    if(l >= al && r <= ar)
    {
        Tree[v] = 1;
        Tree_push[v] = 1;
    }
    else if(l <= ar && r >= al)
    {
        push(v);
        update(v * 2, l, (r + l) / 2, al, ar);
        update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
        Tree[v] = Tree[v] | Tree[v * 2] | Tree[v * 2 + 1];
    }
}
int n, q;
bool up_(int a, int b)
{
    if(a == b)
    {
        return 0;
    }
    while(1)
    {
        if(pr(mass[st[a]], b))
        {
            if(ask(1, 0, n - 1, idx[b] + 1, idx[a]))
            {
                return 1;
            }
            return 0;
        }
        else
        {
            if(ask(1, 0, n - 1, st[a], idx[a]))
            {
                return 1;
            }
            a = pred_tree[mass[st[a]]];
        }
    }
}
void add(int a, int b)
{
    if(a == b)
    {
        return;
    }
    while(1)
    {
        if(pr(mass[st[a]], b))
        {
            update(1, 0, n - 1, idx[b] + 1, idx[a]);
            break;
        }
        else
        {
            update(1, 0, n - 1, st[a], idx[a]);
            a = pred_tree[mass[st[a]]];
        }
    }
}
int lca(int a, int b)
{
    if(pr(a, b))
    {
        return a;
    }
    for(int j = T - 1; j >= 0;j --)
    {
        if(!pr(up[j][a], b))
        {
            a = up[j][a];
        }
    }
    return up[0][a];
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >>q;
    for(int i = 0; i < n; i++)
    {
        dsu[i] = i;
        rang[i] = 1;
    }
    vector <bool> ans(q);
    vector <vector <int> > vec;
    for(int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        vec.push_back({a, b, c});
        if(pred(a) != pred(b))
        {
            g[a].push_back({b, c});
            g[b].push_back({a, c});
            unite(a, b);
            ans[i] = 1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(!used[i])
        {
            up[0][i] = i;
            dfs(i);
            st[i] = it;
            idx[i] = it;
            mass[it++] = i;
            dfs1(i);
        }
    }
    for(int i = 1; i < T; i++)
    {
        for(int j = 0; j < n; j++)
        {
            up[i][j]  = up[i - 1][up[i - 1][j]];
        }
    }
    for(int i = 0; i < q; i++)
    {
        if(ans[i])
        {
            continue;
        }
        int a =vec[i][0];
        int b = vec[i][1];
        int c = vec[i][2];
        if((val[a] ^ val[b] ^ c) == 0)
        {
            continue;
        }
        int t = lca(a, b);
        if(!up_(a, t) && !up_(b, t))
        {
            ans[i] = 1;
            add(a, t);
            add(b, t);
        }
    }
    for(int i = 0; i < q; i++)
    {
        if(ans[i])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}