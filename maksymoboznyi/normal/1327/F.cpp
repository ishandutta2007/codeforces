#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 5e5 + 5;
const int M = 998244353;

struct cell {
    int l, r, x;
};

int n, m, k, t[4 * N], is[N], add[N];
long long ans = 1;
cell a[N], b[N];
vector<int> l[N];

/*void upd(int v, int vl, int vr, int pos, int val) {
    t[v] += val;
    t[v] %= M;
    if (vl == vr) {
        return;
    }
    int vm = (vl + vr) / 2;
    if (pos <= vm)
        upd(v + v, vl, vm, pos, val);
    else
        upd(v + v + 1, vm + 1, vr, pos, val);
}

int get(int v, int vl, int vr, int l, int r) {
    if (l > r)
        return 0;
    if (vl == l && vr == r)
        return t[v];
    int vm = (vl + vr) / 2;
    return (get(v + v, vl, vm, l, min(r, vm)) + get(v + v + 1, vm + 1, vr, max(l, vm + 1), r)) % M;
}*/

void upd(int r, int val) {
    for (; r <= n; r = (r | (r + 1)))
        t[r] += val, t[r] %= M;
}

int sum(int r) {
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        res += t[r], res %= M;
    return res;
}

int get(int l, int r) {
    return (sum(r) - sum(l - 1) + M) % M;
}

void solve() {
    for (int i = 1; i <= m; i++)
        if (b[i].x == 1)
            add[b[i].l]++, add[b[i].r + 1]--;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += add[i];
        if (cur > 0)
            is[i] = 1;
    }
    upd(0, 1);
    int cur_l = 0;
    for (int i = 1; i <= m; i++)
        if (b[i].x == 0)
            l[b[i].r].pb(b[i].l);
    for (int i = 1; i <= n; i++) {
        if (!is[i])
            upd(i, get(cur_l, i - 1));
        for (auto pos: l[i])
            cur_l = max(pos, cur_l);
    }
    ans *= get(cur_l, n);
    ans %= M;
}



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i].l >> a[i].r >> a[i].x;
    for (int bit = 0; bit < k; bit++) {
        for (int i = 1; i <= m; i++)
            b[i] = a[i], b[i].x = ((a[i].x >> bit) & 1);
        for (int i = 0; i <= 4 * n + 4; i++)
            t[i] = 0;
        for (int i = 1; i <= n; i++)
            add[i] = is[i] = 0;
        for (int i = 1; i <= n; i++)
            l[i].clear();
        solve();
    }
    cout << ans << "\n";
    return 0;
}