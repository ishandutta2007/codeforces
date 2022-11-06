#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 1e6 + 5;

struct cell {
    int a, b, z;
};

int n, m, k, cb[N], dp[N];
pair<int, int> a[N];
cell c[N];

int t[4*N], p[4*N];

void build(int v, int vl, int vr) {
    if (vl == vr) {
        t[v] = -cb[vl];
        return;
    }
    int vm = (vl + vr) / 2;
    build(v + v, vl, vm);
    build(v + v + 1, vm + 1, vr);
    t[v] = max(t[v + v], t[v + v + 1]);
}

int push(int v) {
    p[v + v] += p[v];
    t[v + v] += p[v];

    p[v + v + 1] += p[v];
    t[v + v + 1] += p[v];

    p[v] = 0;
}

void add(int v, int vl, int vr, int l, int r, int val) {
    if (l > r)
        return;
    if (vl == l && vr == r) {
        t[v] += val;
        p[v] += val;
        return;
    }
    push(v);
    int vm = (vl + vr) / 2;
    add(v + v, vl, vm, l, min(r, vm), val);
    add(v + v + 1, vm + 1, vr, max(l, vm + 1), r, val);
    t[v] = max(t[v + v], t[v + v + 1]);
}

int get(int v, int vl, int vr, int l, int r) {
    if (l > r)
        return -1e18;
    if (vl == l && vr == r)
        return t[v];
    push(v);
    int vm = (vl + vr) / 2;
    return max(get(v + v, vl, vm, l, min(r, vm)), get(v + v + 1, vm + 1, vr, max(l, vm + 1), r));
}

bool cmp(cell a, cell b) {
    if (a.a != b.a)
        return a.a < b.a;
    return a.b < b.b;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;

    for (int i = 0; i <= 1e6; i++)
        cb[i] = 1e18;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        cb[x] = min(cb[x], y);
    }
    for (int i = 1e6 - 1; i >= 0; i--)
        cb[i] = min(cb[i + 1], cb[i]);
    for (int i = 1; i <= k; i++)
        cin >> c[i].a >> c[i].b >> c[i].z;
    sort(c + 1, c + k + 1, cmp);
    build(1, 1, 1e6);

    dp[0] = -cb[0];

    for (int i = 1; i <= k; i++) {
        add(1, 1, 1e6, c[i].b + 1, 1e6, c[i].z);
        dp[i] = get(1, 1, 1e6, 1, 1e6);
    }
    int cur_sum = 0, cur_r = 1;
    sort(a + 1, a + n + 1);
    int ans = -1e18;
    for (int i = 1; i <= n; i++) {
        while (cur_r <= k && c[cur_r].a < a[i].first)
            cur_r++;
        ans = max(ans, dp[cur_r - 1] - a[i].second);
    }
    cout << ans;

    return 0;
}