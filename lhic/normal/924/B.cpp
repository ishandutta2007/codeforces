#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;

const int MAXN = 200228;
ll a[MAXN];

int main() {
#ifdef PAUNSVOKNO
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(nullptr); cin.tie(nullptr);
    ld ans = -1.0;
    int n, u;
    cin >> n >> u;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int k = 0;
    for (int i = 0; i < n; ++i) {
        while ((k + 1 < n) && a[k + 1] <= a[i] + u) {
            ++k;
        }

        if (k >= i + 2) {
            ans = max(ans, ld(a[k] - a[i + 1]) / ld(a[k] - a[i]));
        }
    }

    if (ans > 0) {
        cout << ans << "\n";
    } else {
        cout << -1 << "\n";
    }
}