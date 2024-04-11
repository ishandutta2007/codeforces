#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, x[200010], a[200010], v, ans[200010], l[200010], r[200010], cnt;
ll pos[400010];
int c[400010];
void add(int x, int k) {
    for (; x <= cnt; x += x & -x) c[x] = max(c[x], k);
}
void rmv(int x) {
    for (; x <= cnt; x += x & -x) c[x] = -n;
}
int query(int x) {
    int ans = -n;
    for (; x; x -= x & -x) ans = max(ans, c[x]);
    return ans;
}
void solve(int l, int r, vector <int> p) {
    if (l == r) return;
    vector <int> lp, rp;
    int mid = l + r >> 1;
    for (auto i : p) if (i <= mid) lp.push_back(i); else rp.push_back(i);
    solve(l, mid, lp);
    for (auto i : p) if (i <= mid) add(::r[i], ans[i] + 1); else ans[i] = max(ans[i], query(::r[i]));
    for (auto i : p) if (i <= mid) rmv(::r[i]);
    solve(mid + 1, r, rp);
}
int main() {
    scanf("%d%d", &n, &v);
    for (int i = 1; i <= n; i++) scanf("%d", x + i);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 0; i <= n; i++) {
        pos[++cnt] = a[i] - 1ll * x[i] * v;
        pos[++cnt] = a[i] + 1ll * x[i] * v;
    }
    sort(pos + 1, pos + 1 + cnt);
    for (int i = 0; i <= n; i++) {
        l[i] = lower_bound(pos + 1, pos + 1 + cnt, a[i] - 1ll * x[i] * v) - pos;
        r[i] = lower_bound(pos + 1, pos + 1 + cnt, a[i] + 1ll * x[i] * v) - pos;
        l[i] = cnt + 1 - l[i];
    }
    for (int i = 1; i <= n; i++) ans[i] = -n;
    for (int i = 1; i <= cnt; i++) c[i] = -n;
    vector <int> st;
    for (int i = 0; i <= n; i++) st.push_back(i);
    sort(st.begin(), st.end(), [](int x, int y) {
        return l[x] == l[y] ? x < y : l[x] < l[y];
    });
    solve(0, n, st);
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, ::ans[i]);
    cout << ans << endl;
}