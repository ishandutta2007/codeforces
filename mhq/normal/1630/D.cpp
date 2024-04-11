#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 1e6 + 10;
ll a[maxN];
int b[maxN];
void solve() {
    cin >> n >> m;
    int d = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        if (i == 1) d = b[i];
        else d = __gcd(d, b[i]);
    }
    ll ans = 0;
    ll f1 = 0;
    ll f2 = 0;
    for (int i = 1; i <= d; i++) {
        ll sum_abs = 0;
        ll min_abs = 1e18;
        int need = 0;
        for (int j = i; j <= n; j += d) {
            sum_abs += llabs(a[j]);
            if (a[j] < 0) {
                need ^= 1;
            }
            min_abs = min(min_abs, llabs(a[j]));
        }
        if (need == 0) {
            f1 += sum_abs;
            f2 += sum_abs - 2 * min_abs;
        }
        else {
            f1 += sum_abs - 2 * min_abs;
            f2 += sum_abs;
        }
    }
    cout << max(f1, f2) << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}