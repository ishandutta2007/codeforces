#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
ll a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        ll s = 0;
        ll t = 0;
        ll best = -5e18;
        for (int i = 2; i <= n; i++) {
            s += (a[1] + a[i]);
            t += a[1] * a[i];
        }
        if (s > 0) {
            cout << "INF\n";
            continue;
        }

        s = 0;
        t = 0;
        for (int i = 1; i < n; i++) {
            s += (a[i] + a[n]);
            t += a[i] * a[n];
        }
        if (s < 0) {
            cout << "INF\n";
            continue;
        }
        ll sum_smaller = 0;
        ll sum_bigger = 0;
        for (int i = 2; i <= n; i++) {
            sum_bigger += a[i];
        }
        for (int i = 1; i <= n; i++) {
            ll t = -a[i];
            ll F = sum_smaller * a[n];
            F += sum_bigger * a[1];
            F += t * sum_smaller;
            F += (i - 1) * a[n] * t;
            F += (n - i) * a[1] * t;
            F += t * sum_bigger;
            F += t * a[i];
            F -= (a[1] * a[n] + t * (a[1] + a[n]));
            best = max(best, F);
            sum_smaller += a[i];
            sum_bigger -= a[i + 1];
        }
        cout << best << '\n';
    }
    return 0;
}