#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 200005;
const long long INF = 1E15 + 7;

int n, ans[N];
long long a[N];

struct STree
{
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

    pair<long long, int> tr[4 * N];
    long long lz[4 * N];

    void down(int i)
    {
        tr[lc].fi += lz[i]; lz[lc] += lz[i];
        tr[rc].fi += lz[i]; lz[rc] += lz[i];
        lz[i] = 0;
    }

    void build(int l, int r, int i)
    {
        if (l == r)
        {
            tr[i] = {a[l], -l};
            return;
        }
        build(l, m, lc);
        build(m + 1, r, rc);
        tr[i] = min(tr[lc], tr[rc]);
    }

    void update(int l, int r, int i, int L, int R, long long v)
    {
        if (l > R || r < L || L > R)
            return;
        if (L <= l && r <= R)
        {
            tr[i].fi += v;
            lz[i] += v;
            return;
        }
        down(i);
        update(l, m, lc, L, R, v);
        update(m + 1, r, rc, L, R, v);
        tr[i] = min(tr[lc], tr[rc]);
    }

#undef m
#undef lc
#undef rc
} seg;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    seg.build(1, n, 1);
    for (int i = 1; i <= n; i++)
    {
        pair<long long, int> cur = seg.tr[1];
        cur.se *= -1;
        ans[cur.se] = i;
        seg.update(1, n, 1, cur.se, cur.se, INF);
        seg.update(1, n, 1, cur.se + 1, n, -i);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}