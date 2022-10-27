#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;
#define int long long
const int N = 2e5;
const int t = 20;
vector <int> g[N];
int n;
long long ans = 0;
int vL[N], rL[N], vR[N], rR[N];
int up[t][N];
int tin[N], tout[N];
int h[N];
int timer = 0;
long long post[N];
bool pred(int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}
int rmq[t][N * 2];
void dfs(int v, int p = -1)
{
    tin[v] = timer;
    rmq[0][timer] = v;
    timer++;
    for(int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if(to != p)
        {
            h[to] = h[v] + 1;
            up[0][to] = v;
            dfs(to, v);
            rmq[0][timer] = v;
            timer++;
        }
    }
    tout[v] = timer - 1;
}
int Log2[N * 2];
int lca(int a, int b)
{
    int l = min(tin[a], tin[b]);
    int r = max(tin[a], tin[b]);
    int qw = Log2[r - l + 1];
    int v = rmq[qw][l];
    int u = rmq[qw][r - (1 << qw) + 1];
    if(h[v] < h[u])
    {
        return v;
    }
    return u;
}
int dist(int a, int b)
{
    int a1 = lca(a, b);
    return h[a] + h[b] - 2 * h[a1];
}
int go_up(int a, int len)
{
    for(int j = t - 1; j >= 0; j--)
    {
        if(len >= (1 << j))
        {
            a = up[j][a];
            len -= (1 << j);
        }
    }
    return a;
}
int go_to(int from, int to, int len)
{
    int u = lca(from, to);
    if(h[from] - h[u] < len)
    {
        return go_up(to, dist(from, to) - len);
    }
    else
    {
        return go_up(from, len);
    }
}
pair <int, int> merge(int v1, int r1, int v2, int r2)
{
    if(dist(v1, v2) <= max(r1, r2) - min(r1, r2))
    {
        if(r1 > r2)
        {
            return {v1, r1};
        }
        return {v2, r2};
    }
    else
    {
        int R = (dist(v1, v2) + r1 + r2);
        assert(R % 2 == 0);
        R /= 2;
        int vc = go_to(v1, v2, R - r1);
        return {vc, R};
    }
}
long long sum[N];
int all_cnt[N];
vector <long long> add_sum[N];
vector <int> add_cnt[N];
int par[N];
int up_ind[N];
int _sz[N];
int colored[N];
void dfs1(int v, int p = -1)
{
    _sz[v] = 1;
    for(int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if(to != p && !colored[to])
        {
            dfs1(to, v);
            _sz[v] += _sz[to];
        }
    }
}
int centroid(int v, int sz1, int p = -1)
{
    for(int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if(to != p && _sz[to] * 2 >= sz1 && !colored[to])
        {
            return centroid(to, sz1, v);
        }
    }
    return v;
}
void build_centroid(int v, int ind = -1, int p = -1)
{
    dfs1(v);
    v = centroid(v, _sz[v]);
    par[v] = p;
    colored[v] = 1;
    up_ind[v] = ind;
    int it = 0;
    for(int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if(!colored[to])
        {
            build_centroid(to, it, v);
            it++;
        }
    }
    add_sum[v].resize(it, 0);
    add_cnt[v].resize(it, 0);
}
bool check(int v1, int r1, int v2, int r2)
{
    return dist(v1, v2) <= r2 - r1;
}
void add(int v)
{
    int u = v;
    int ind = -1;
    while(u != -1)
    {
        all_cnt[u]++;
        sum[u] += dist(u, v);
        if(u != v)
        {
            add_sum[u][ind] += dist(u, v);
            add_cnt[u][ind]++;
        }
        ind = up_ind[u];
        u = par[u];
    }
}
void del(int v)
{
    int u = v;
    int ind = -1;
    while(u != -1)
    {
        all_cnt[u]--;
        sum[u] -= dist(u, v);
        if(u != v)
        {
            add_sum[u][ind] -= dist(u, v);
            add_cnt[u][ind]--;
        }
        ind = up_ind[u];
        u = par[u];
    }
}
long long funct(int v)
{
    long long sum1 = 0;
    int u = v;
    int ind = -1;
    while(u != -1)
    {
        sum1 += all_cnt[u] * dist(u, v);
        sum1 += sum[u];
        if(u != v)
        {
            sum1 -= add_cnt[u][ind] * dist(u, v);
            sum1 -= add_sum[u][ind];
        }
        ind = up_ind[u];
        u = par[u];
    }
    return sum1;
}
void solve(int l, int r)
{
    if(l == r)
    {
        return;
    }
    int midd = (r + l) / 2;
    solve(l, midd);
    solve(midd + 1, r);
    for(int i = 0; i <= midd - l; i++)
    {
        vL[i] = midd - i;
        rL[i] = 0;
        if(i != 0)
        {
            pair <int, int> t = merge(vL[i], rL[i], vL[i - 1], rL[i - 1]);
            vL[i] = t.first;
            rL[i] = t.second;
        }
    }
    for(int i = 0; i <= r - midd - 1; i++)
    {
        vR[i] = midd + 1 + i;
        rR[i] = 0;
        if(i != 0)
        {
            pair <int, int>  t = merge(vR[i], rR[i], vR[i - 1], rR[i - 1]);
            vR[i] = t.first;
            rR[i] = t.second;
        }
    }
    for(int i = r - midd - 1; i >= 0; i--)
    {
        post[i] = rR[i];
        if(i != r - midd - 1)
        {
            post[i] += post[i + 1];
        }
    }
    int L = 0, R = 0;
    for(int i = 0; i <= midd - l; i++)
    {
        while(R < r - midd && !check(vL[i], rL[i], vR[R], rR[R]))
        {
            add(vR[R]);
            R++;
        }
        while(L < R && check(vR[L], rR[L], vL[i], rL[i]))
        {
            del(vR[L]);
            L++;
        }
        ans += 1LL * L * rL[i] * 2;
        if(R < r - midd)
        {
            ans += 1LL * post[R] * 2;
        }
        if(R - L > 0)
        {
            ans += 1LL * post[L];
            if(R < r - midd)
            {
                ans -= 1LL * post[R];
            }
        }
        ans += 1LL * (R - L) * rL[i];
        ans += funct(vL[i]);
    }
    /*for(int i = 0;i <= midd - l; i++)
    {
        cout << rL[i] << " ";
    }
    for(int i = 0; i <= r - midd - 1; i++)
    {
        cout << rR[i] << " ";
    }
    cout << "\n";
    */while(L < R)
    {
        del(vR[L]);
        L++;
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Log2[1] = 0;
    for(int i = 2; i < N * 2; i++)
    {
        Log2[i] = Log2[i / 2] + 1;
    }
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(n + i);
        g[b].push_back(n + i);
        g[n + i].push_back(a);
        g[n + i].push_back(b);
    }
    h[0] = 0;
    dfs(0);
    for(int i = 1; i < t; i++)
    {
        for(int j = 0; j < n * 2; j++)
        {
            up[i][j] = up[i - 1][up[i -1][j]];
        }
    }
    for(int i = 1; i < t; i++)
    {
        for(int j = 0; j + (1 << i) <= 4 * n; j++)
        {
            int a = rmq[i - 1][j];
            int b = rmq[i - 1][j + (1 << (i - 1))];
            if(h[a] < h[b])
            {
                rmq[i][j] = a;
            }
            else{
                rmq[i][j] = b;
            }
        }
    }
    build_centroid(0);
    solve(0, n - 1);
    assert(ans % 2 == 0);
    cout << ans / 2;
    return 0;
}