#include <bits/stdc++.h>

using namespace std;

int n, m = 300000;
long long a[500005];
long long f[500005], g[500005];

void upd(long long *t, int l, int r, long long x) {
    for (int y = l; y <= m; y += y & -y) t[y] += x;
    for (int y = r + 1; y <= m; y += y & -y) t[y] -= x;
}
long long get(long long *t, int p) {
    long long ret = 0;
    for (; p; p -= p & -p) ret += t[p];
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    //for (int i = 1; i <= n; ++i) a[i] = i;
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        long long add = get(f, a[i]), cnt = 0;
        for (int val = 1; val * a[i] <= m; ++val) {
            int l = val * a[i], r = min(m * 1LL, (val + 1) * a[i] - 1);
            cnt += (get(g, r) - get(g, l - 1)) * val;
        }
        ans += add - a[i] * cnt + a[i] * (i - 1);
        cout << ans << ' ';
        upd(f, 1, m, a[i]);
        upd(g, a[i], m, 1);
        for (int val = 1; val * a[i] <= m; ++val) {
            int l = val * a[i], r = min(m * 1LL, (val + 1) * a[i] - 1);
            upd(f, l, r, -a[i] * val);
        }
    }
    return 0;
}