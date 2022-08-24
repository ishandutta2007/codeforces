#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3e6 + 10;
ll a[maxN], b[maxN];
ll pref[maxN];
const ll INF = 1e18;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        ll f = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            f -= a[i];
            a[i + n] = a[i];
            a[i + 2 * n] = a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            f += b[i];
        }
        if (f < 0) {
            cout << "NO\n";
            continue;
        }
        rotate(b + 1, b + n, b + n + 1);
        for (int i = 1; i <= n; i++) {
            b[i + n] = b[i];
            b[i + 2 * n] = b[i];
        }
        pref[0] = 0;
        for (int i = 1; i <= 3 * n; i++) {
            pref[i] = pref[i - 1] + b[i] - a[i];
        }
        ll mn = INF;
        bool ok = true;
        for (int r = 1; r + 1 <= 3 * n; r++) {
            if (pref[r] + b[r + 1] + mn < 0) {
                cout << "NO\n";
                ok = false;
                break;
            }
            mn = min(mn, -pref[r]);
        }
        if (ok) {
            cout << "YES\n";
        }
    }
    return 0;
}