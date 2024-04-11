
#include <bits/stdc++.h>
#define X first
#define ll long long
#define Y second
#define sz(a) (int)a.size()
using namespace std;
//#define int long long
const int maxn = 1.3e6 + 100;
const int maxm = 26;
const int inf = 1e9;

int n, q, lcp[maxn], m, col[maxn], pw, P[maxn], rnk[maxm][maxn], w[maxn];
int seg[maxn << 2], ptr, a[maxn], S[maxn], f[maxn], par[maxm][maxn];
pair <int, int> b[maxn], mx[maxn << 2], ans[maxn];
string s, t[maxn];
vector <int> vec[maxn << 2], V[maxn], adj[maxn];
vector <pair <pair <int, int>, int> > query[maxn];
bool cmp(int i, int j)
{
    if(rnk[pw - 1][i] != rnk[pw - 1][j])
    {
        return rnk[pw - 1][i] < rnk[pw - 1][j];
    }
    if(max(i, j) + (1 << (pw - 1)) > m)
    {
        return i > j;
    }
    return rnk[pw - 1][i + (1 << (pw - 1))] < rnk[pw - 1][j + (1 << (pw - 1))];
}
void build_SA()
{
    for(int i = 1; i <= m; ++i)
    {
        rnk[0][i] = S[i], P[i] = i;
    }
    for(pw = 1; pw < maxm; pw++)
    {
        sort(P + 1, P + m + 1, cmp);
        for(int i = 2; i <= m; i++)
        {
            rnk[pw][P[i]] = rnk[pw][P[i - 1]] + cmp(P[i - 1], P[i]);
        }
    }
}
int LCP(int x, int y)
{
    int res = 0;
    for(int pw = maxm - 1; pw >= 0; pw--)
    {
        if(rnk[pw][x] == rnk[pw][y])
        {
            res += (1 << pw);
            x += (1 << pw);
            y += (1 << pw);
        }
    }
    return res;
}
void build(int v, int l, int r)
{
    if(l == r)
    {
        seg[v] = lcp[l];
        vec[v].push_back(l);
        return;
    }
    int midd = (r + l) / 2;
    build(v * 2, l, midd);
    build(v * 2 + 1, midd + 1, r);
    if(seg[v * 2] <= seg[v * 2 + 1])
    {
        for(auto x : vec[v * 2])
        {
            vec[v].push_back(x);
        }
    }
    if(seg[v * 2 + 1] <= seg[v * 2])
    {
        for(auto x : vec[v * 2 + 1])
        {
            vec[v].push_back(x);
        }
    }
    seg[v] = min(seg[v * 2], seg[v * 2 + 1]);
}
int get(int v, int l, int r, int al, int ar)
{
    if(ar < l  || al > r)
    {
        return 1e9;
    }
    if(l >= al && r <= ar)
    {
        return seg[v];
    }
    return min(get(v * 2, l, (r + l) / 2, al, ar), get(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
}
void findmin(int v, int l, int r, int al, int ar, int val, int ind)
{
    if(ar < l || al > r)
    {
        return;
    }
    if(seg[v] > val)
    {
        return;
    }
    if(l >= al && r <= ar)
    {
        for(auto x : vec[v])
        {
            V[ind].push_back(x);
        }
        return;
    }
    findmin(v * 2, l, (r + l) / 2, al, ar, val, ind);
    findmin(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val, ind);
}
void suff_tree(int v, int l, int r)
{
    b[v] = {l, r};
    if(l == r)
    {
        if(a[P[l]] > -inf && a[P[l]] <= 0)
        {
            f[-a[P[l]]] = v;
        }
        else if(a[P[l]] > 0)
        {
            col[l] = a[P[l]];
        }
        return;
    }
    w[v] = get(1, 1, m - 1, l, r - 1);
    findmin(1, 1, m - 1, l, r - 1, w[v], v);
    V[v].push_back(r);
    int last = l;
    for(auto x : V[v])
    {
        int u = ++ptr;
        par[0][u] = v;
        adj[v].push_back(u);
        suff_tree(u, last, x);
        last = x + 1;
    }
}
pair <int, int> Max(pair <int, int> i, pair <int, int> j)
{
    if(i.X != j.X)
    {
        return max(i, j);
    }
    return min(i, j);
}
void build1(int v, int l, int r)
{
    if(l == r)
    {
        mx[v].Y = l;
        return;
    }
    build1(v * 2, l, (r + l) / 2);
    build1(v * 2 + 1, (r + l) / 2 + 1, r);
    mx[v] = Max(mx[v * 2], mx[v * 2 + 1]);
}
void modify(int v, int l, int r, int pos, int val)
{
    if(!pos)
    {
        return;
    }
    if(l == r)
    {
        mx[v].X += val;
        return;
    }
    if(pos <= (r + l) / 2)
    {
        modify(v * 2, l, (r + l) / 2, pos, val);
    }
    else
    {
        modify(v * 2 + 1, (r + l) / 2 + 1, r, pos, val);
    }
    mx[v] = Max(mx[v * 2], mx[v * 2 + 1]);
}
pair <int, int> get3(int v, int l, int r, int al, int ar)
{
    if(ar < l || al > r)
    {
        return {0, n};
    }
    if(l >= al && r <= ar)
    {
        return mx[v];
    }
    return Max(get3(v * 2, l, (r + l) / 2, al, ar), get3(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
}
int used[maxn];
void DFS(int v)
{
    int w = 0;
    for(auto to : adj[v])
    {
        if(b[to].Y - b[to].X > b[w].Y - b[w].X)
        {
            w = to;
        }
    }
    for(auto to : adj[v])
    {
        if(to == w)
        {
            continue;
        }
        DFS(to);
        for(int i = b[to].X; i <= b[to].Y; i++)
        {
            modify(1, 1, n, col[i], -1);
        }
    }
    if(w)
    {
        DFS(w);
    }
    for(auto to : adj[v])
    {
        if(to == w)
        {
            continue;
        }
        for(int i = b[to].X; i <= b[to].Y; i++)
        {
            modify(1, 1, n, col[i], 1);
        }
    }
    if(b[v].X == b[v].Y)
    {
        modify(1, 1, n, col[b[v].X], 1);
    }
    for(auto p : query[v])
    {
        used[p.Y] = 1;
        ans[p.Y] = get3(1, 1, n, p.X.X, p.X.Y);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for(int i = 0; i < sz(s); i++)
    {
        S[++m] = s[i];
        a[m] = -i-1;
    }
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> t[i];
        S[++m] = -i-inf;
        for(int j = 0; j < sz(t[i]); j++)
        {
            S[++m] = t[i][j];
            a[m] = i;
        }
    }
    build_SA();
    for(int i = 1; i < m; i++)
    {
        lcp[i] = LCP(P[i], P[i + 1]);
    }
    build(1, 1, m - 1);
    suff_tree(++ptr, 1, m);
    for(int i = 1; i < maxm; i++)
    {
        for(int v = 1; v <= ptr; v++)
        {
            par[i][v] = par[i - 1][par[i - 1][v]];
        }
    }
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int l, r, l2, r2;
        cin >> l >> r >> l2 >> r2;
        int v = f[l2];
        for(int j = maxm - 1; j >= 0; j--)
        {
            if(w[par[j][v]] > r2 - l2)
            {
                v = par[j][v];
            }
        }
        query[v].push_back({{l, r}, i});
    }
    build1(1, 1, n);
    DFS(1);
    for(int i = 0; i < q; i++)
    {
        assert(used[i]);
        cout << ans[i].Y << " " << ans[i].X << "\n";
    }
	return 0;
}