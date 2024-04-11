#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
const int mod = 1e9 + 7;
const int N = 1e6;
const int T = 20;
vector <pair <int, pair <int, int> > > g[N];
int n, m;
int weight[N];
int used[N];
int up[T][N];
int maxup[T][N];
int ans[N];
int tin[N];
int tout[N];
int timer = 0;
int dsu[N];
int rang[N];
int h[N];
int ind[N];
int ind1[N];
int p_up[N], p_up_ind_ver[N];
vector <vector <int> > vertexes;
vector <vector <int> > edges;
vector <vector <int> > Trees, Suf;
int _sz[N];
int pred(int a)
{
    if(a == dsu[a]) return a;
    return dsu[a] = pred(dsu[a]);
}
void unite(int a, int b)
{
    a = pred(a);
    b = pred(b);
    if(a != b)
    {
        if(rang[a] < rang[b])
        {
            swap(a, b);
        }
        dsu[b] = a;
        if(rang[a] == rang[b])
        {
            rang[a]++;
        }
    }
}
void dfs(int v, int p = -1)
{
    _sz[v] = 1;
    tin[v] = timer++;
    for(auto to : g[v])
    {
        if(to.X != p)
        {
            h[to.X] = h[v] + 1;
            p_up[to.X] = v;
            p_up_ind_ver[to.X] = to.Y.Y;
            up[0][to.X] = v;
            maxup[0][to.X] = to.Y.X;
            dfs(to.X, v);
            _sz[v] += _sz[to.X];
        }
    }
    tout[v] = timer++;
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
    for(int j = T - 1; j >= 0; j--)
    {
        if(!pred(up[j][a], b))
        {
            a = up[j][a];
        }
    }
    return up[0][a];
}
int max_val(int a, int b)
{
    int ans = 0;
    for(int j = T - 1; j >= 0; j--)
    {
        if(!pred(up[j][a], b))
        {
            ans = max(ans, maxup[j][a]);
            a = up[j][a];
        }
    }
    for(int j = T - 1; j >= 0; j--)
    {
        if(!pred(up[j][b], a))
        {
            ans = max(ans, maxup[j][b]);
            b = up[j][b];
        }
    }
    if(!pred(a, b))
    {
        ans = max(ans, maxup[0][a]);
    }
    if(!pred(b, a))
    {
        ans = max(ans, maxup[0][b]);
    }
    return ans;
}
vector <int> ver, ed;
void dfs2(int v, int p = -1)
{
    ver.push_back(v);
    for(auto to : g[v])
    {
        if(to.X == p)
        {
            continue;
        }
        if(_sz[to.X] * 2 >= _sz[v])
        {
            ed.push_back(to.Y.Y);
            dfs2(to.X, v);
        }
    }
    if(sz(ed) > 0)
    {
        reverse(ver.begin(), ver.end());
        reverse(ed.begin(), ed.end());
        Trees.push_back({});
        Trees[sz(vertexes)].resize(4 * sz(ver), 1e9);
        Suf.push_back({});
        ver.pop_back();
        Suf[sz(vertexes)].resize(sz(ver), 1e9);
        for(int u = 0; u < sz(ver); u++)
        {
            ind[ver[u]] = sz(vertexes);
            ind1[ver[u]] = u;
        }
        edges.push_back(ed);
        vertexes.push_back(ver);
    }
    ed.clear();
    ver.clear();
    for(auto to : g[v])
    {
        if(to.X == p)
        {
            continue;
        }
        if(_sz[to.X] * 2 < _sz[v])
        {
            dfs2(to.X, v);
        }
    }
}
void minimize(int &a, int b)
{
    a = min(a, b);
}
void update(int ind, int v, int l, int r, int al, int ar, int val)
{
    if(al > ar)
    {
        return;
    }
    if(l >= al && r <= ar)
    {
        Trees[ind][v] = min(Trees[ind][v], val);
    }
    else if(l <= ar && r >= al)
    {
        update(ind, v * 2, l, (r + l) / 2, al, ar, val);
        update(ind, v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
    }
}
int ans1(int ind, int v, int l, int r, int x)
{
    if(l == r)
    {
        return Trees[ind][v];
    }
    if(x <= (r + l) / 2)
    {
        return min(Trees[ind][v], ans1(ind, v * 2, l, (r + l) / 2, x));
    }
    return min(Trees[ind][v], ans1(ind, v  * 2 + 1, (r + l) / 2 + 1, r, x));
}
void go_to(int from, int to, int val)
{
    int cnt = 0;
    while(from != to)
    {
        cnt++;
        if(ind[from] == -1)
        {
            minimize(ans[p_up_ind_ver[from]], val);
            from = p_up[from];
        }
        else if(ind[from] == ind[to])
        {
            int u = ind1[from];
            int u1 = ind1[to];
            update(ind[from], 1, 0, sz(edges[ind[from]]) - 1, u, u1 - 1, val);
            from = to;
        }
        else
        {
            int u = ind1[from];
            minimize(Suf[ind[from]][u], val);
            from = p_up[vertexes[ind[from]].back()];
        }
        assert(cnt <= 20);
    }
}
pair <int, int>wer[N];
int idx[N];
bool cmp(int a, int b)
{
    return weight[a] < weight[b];
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> n >> m;
    fill(ans, ans + m, 1e9);
    fill(ind, ind + n, -1);
    for(int i = 0; i < n; i++)
    {
        dsu[i]= i;
        rang[i] = 1;
    }
    fill(used, used + n, 0);
   // assert(m <= 100000);
    for(int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        weight[i] = w;
        idx[i] = i;
        wer[i] = {a, b};
    }
  //  assert(m <= 100000);
    sort(idx, idx + m, cmp);
    //assert(m <= 100000);
    for(int j = 0; j < m; j++)
    {
        int i = idx[j];
        int a = wer[i].X;
        int b = wer[i].Y;
        if(pred(a) != pred(b))
        {
            used[i] = 1;
            unite(a, b);
            g[a].push_back({b, {weight[i], i}});
            g[b].push_back({a, {weight[i], i}});
        }
    }
  //  assert(m <= 100000);
    dfs(0);
    for(int t = 1; t < T; t++)
    {
        for(int i = 0; i < n; i++)
        {
            up[t][i] = up[t - 1][up[t - 1][i]];
            maxup[t][i] = max(maxup[t - 1][i], maxup[t - 1][up[t - 1][i]]);
        }
    }
   // assert(m <= 100000);
    dfs2(0);
    for(int i = 0; i < m; i++)
    {
        if(used[i])
        {
            continue;
        }
        int u = max_val(wer[i].X, wer[i].Y);
        ans[i] = u;
        int lca_ = lca(wer[i].X, wer[i].Y);
        go_to(wer[i].X, lca_, weight[i]);
        go_to(wer[i].Y, lca_, weight[i]);
    }
    for(int i = 0; i < sz(edges); i++)
    {
        int t = 1e9;
        for(int j = 0; j < sz(edges[i]); j++)
        {
            t = min(t, Suf[i][j]);
            minimize(ans[edges[i][j]], ans1(i, 1, 0, sz(edges[i]) - 1, j));
            minimize(ans[edges[i][j]], t);
        }
    }
    for(int i = 0; i < m; i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}