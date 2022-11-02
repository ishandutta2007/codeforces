#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

struct BIT {
    static const int maxn = 100100;
    ld bit[maxn];

    void upd(int i, ld v) {
        for (; i < maxn; i += i & -i) bit[i] += v;
    }

    ld qry(int i) {
        ld ret = 0;
        for (; i > 0; i -= i & -i) ret += bit[i];
        return ret;
    }

    ld qry(int l, int r) {
        return qry(r) - qry(l - 1);
    }

} b1, b2, b3;

int n;

int main() {
    ios_base::sync_with_stdio(0);

    ld ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        ans += b1.qry(p, n);
        ans += b2.qry(p) - b2.qry(p, n);
        ans += (b3.qry(p) - b3.qry(p, n)) * i;
        b1.upd(p, 1);
        b2.upd(p, ld(i) / n);
        b3.upd(p, -ld(i) / n / (n + 1));
    }
    cout << fixed << setprecision(10) << ans << '\n';
}