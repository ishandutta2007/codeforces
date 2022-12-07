#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000000 + 1;
int sum[maxn << 2], psum[maxn << 2];
#define ls (v << 1)
#define rs (ls | 1)
#define tm midpoint(tl, tr)
void build(int v, int tl, int tr) {
    sum[v] = tr - tl + 1;
    psum[v] = 0;
    if (tl == tr) return;
    build(ls, tl, tm);
    build(rs, tm + 1, tr);
}
void add(int v, int tl, int tr, int p, int x) {
    sum[v] += x;
    if (tl == tr) psum[v] = min(sum[v], 0);
    else {
        if (p <= tm) add(ls, tl, tm, p, x);
        else add(rs, tm + 1, tr, p, x);
        psum[v] = min(psum[ls], sum[ls] + psum[rs]);
    }
}
int BIT[maxn];
void add(int u, int m) {
    for (; u <= m; u += u & -u) BIT[u] += 1;
}
int fsum(int u) {
    int res = 0;
    for (; u; u -= u & -u) res += BIT[u];
    return res;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m), c(n);
        vector<pair<int, int>> pa(n);
        for (int i = 0; i < n; i += 1) {
            cin >> a[i];
            pa[i] = {a[i], i};
            c[i] = a[i];
        }
        for (int& x : b) cin >> x;
        LL ans = 0;
        sort(c.begin(), c.end());
        c.resize(unique(c.begin(), c.end()) - c.begin());
        for (int i = 1; i <= (int)c.size(); i += 1) BIT[i] = 0;
        for (int i = n - 1; i >= 0; i -= 1) {
            int p = lower_bound(c.begin(), c.end(), a[i]) - c.begin() + 1;
            add(p, c.size());
            ans += fsum(p - 1);
        }
        sort(a.begin(), a.end());
        sort(pa.begin(), pa.end());
        sort(b.begin(), b.end());
        build(1, 1, n);
        for (int i = 0, s = 0, t = 0; i < m; i += 1) {
            ans += lower_bound(a.begin(), a.end(), b[i]) - a.begin();
            while (s < n and pa[s].first < b[i]) add(1, 1, n, pa[s ++ ].second + 1, -1); 
            while (t < n and pa[t].first <= b[i]) add(1, 1, n, pa[t ++].second + 1, -1);
            ans += psum[1];
           //cout << lower_bound(a.begin(), a.end(), b[i]) - a.begin() << " " << psum[1] << "\n";
        }
        cout << ans << "\n";
    }
    return 0;
}