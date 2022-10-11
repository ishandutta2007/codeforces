#include <bits/stdc++.h>
using namespace std;

const int N = 100005, Q = 100005;

int n, q, l, r, cur = 0, a[N], cnt[N], ans[Q];

struct SQuery
{
    int l, r, ind;
} que[Q];

void add(int u, int v)
{
    if (u >= N)
        return;
    cur -= (cnt[u] == u);
    cnt[u] += v;
    cur += (cnt[u] == u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= q; i++)
    {
        cin >> que[i].l >> que[i].r;
        que[i].ind = i;
    }
    int d = max(1.0, n / sqrt(q));
    sort(que + 1, que + q + 1, [&](const SQuery &a, const SQuery &b) {
        return a.l / d < b.l / d || (a.l / d == b.l / d && a.r < b.r);
    });
    int l = 1, r = 0;
    for (int i = 1; i <= q; i++)
    {
        while (r < que[i].r)
            add(a[++r], 1);
        while (r > que[i].r)
            add(a[r--], -1);
        while (l > que[i].l)
            add(a[--l], 1);
        while (l < que[i].l)
            add(a[l++], -1);
        ans[que[i].ind] = cur;
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}