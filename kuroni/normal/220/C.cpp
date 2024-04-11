#include <bits/stdc++.h>
using namespace std;

const int N = 100005, INF = 1E9 + 7;

int n, a[N], b[N], ind[N];
vector<int> upd[N];

struct STree
{
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

    int lz = 0, tr[4 * N];

    void update(int l, int r, int i, int u, int v)
    {
        if (l == r)
        {
            tr[i] = v - lz;
            return;
        }
        if (u <= m)
            update(l, m, lc, u, v);
        else
            update(m + 1, r, rc, u, v);
        tr[i] = min(tr[lc], tr[rc]);
    }

    int query()
    {
        return tr[1] + lz;
    }

#undef m
#undef lc
#undef rc
} pos, neg;

void update(int u, int dis)
{
    // cout << u << ": " << dis << '\n';
    if (dis >= 0)
    {
        pos.update(1, n, 1, u, dis);
        neg.update(1, n, 1, u, INF);
    }
    else
    {
        neg.update(1, n, 1, u, -dis);
        pos.update(1, n, 1, u, INF);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = n; i >= 1; i--)
    {
        cin >> a[i];
        ind[a[i]] = i;
    }
    for (int i = n; i >= 1; i--)
    {
        cin >> b[i];
        upd[(ind[b[i]] + n - i) % n].push_back(b[i]);
        update(b[i], ind[b[i]] - i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << min(pos.query(), neg.query()) << '\n';
        pos.lz--; neg.lz++;
        for (int &v : upd[i])
            update(v, -1);
        update(b[n - i], ind[b[n - i]] - 1);
    }
}