#include <iostream>
#include <cstdio>
#include <vector>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int N = 500005, Q = 500005;
const long long INF = 1E18 + 7;

int n, q, u, w, l, r, in[N], out[N], cnt = 0;
long long ans[Q];
vector<pair<int, int>> adj[N];
vector<pair<pair<int, int>, int>> que[N];

class CTree
{
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

  private:
    long long val[4 * N], lz[4 * N];

    void down(int i)
    {
        val[lc] += lz[i]; lz[lc] += lz[i];
        val[rc] += lz[i]; lz[rc] += lz[i];
        lz[i] = 0;
    }

  public:
    void upd(int l, int r, int i, int L, int R, long long v)
    {
        if (l > R || r < L)
            return;
        if (L <= l && r <= R)
        {
            val[i] += v; lz[i] += v;
            return;
        }
        down(i);
        upd(l, m, lc, L, R, v);
        upd(m + 1, r, rc, L, R, v);
        val[i] = min(val[lc], val[rc]);
    }

    long long que(int l, int r, int i, int L, int R)
    {
        if (l > R || r < L)
            return INF;
        if (L <= l && r <= R)
            return val[i];
        down(i);
        return min(que(l, m, lc, L, R), que(m + 1, r, rc, L, R));
    }

#undef m
#undef lc
#undef rc
} seg;

void DFS(int u, long long w = 0)
{
    in[u] = ++cnt;
    seg.upd(1, n, 1, in[u], in[u], adj[u].empty() ? w : INF);
    for (pair<int, int> &v : adj[u])
        DFS(v.fi, w + v.se);
    out[u] = cnt;
}

void find_ans(int u)
{
    for (pair<pair<int, int>, int> &v : que[u])
        ans[v.se] = seg.que(1, n, 1, v.fi.fi, v.fi.se);
    for (pair<int, int> &v : adj[u])
    {
        seg.upd(1, n, 1, 1, n, v.se);
        seg.upd(1, n, 1, in[v.fi], out[v.fi], -2 * v.se);
        find_ans(v.fi);
        seg.upd(1, n, 1, in[v.fi], out[v.fi], 2 * v.se);
        seg.upd(1, n, 1, 1, n, -v.se);
    }
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d%d", &u, &w);
        adj[u].push_back(mp(i, w));
    }
    DFS(1);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d%d", &u, &l, &r);
        que[u].push_back(mp(mp(l, r), i));
    }
    find_ans(1);
    for (int i = 1; i <= q; i++)
        printf("%lld\n", ans[i]);
}