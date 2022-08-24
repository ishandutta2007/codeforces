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
ll pref_odd[maxN], pref_even[maxN];
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
            if (i % 2 == 0) {
                pref_even[i] = a[i];
                pref_odd[i] = 0;
            }
            else {
                pref_odd[i] = a[i];
                pref_even[i] = 0;
            }
            pref_odd[i] += pref_odd[i - 1];
            pref_even[i] += pref_even[i - 1];
        }
        ll best = pref_odd[n];
        const ll INF = 1e18;
        ll mx[2] = {0, -INF};
        for (int r = 1; r <= n; r++) {
            best = max(best, pref_odd[n] - pref_odd[r] + pref_even[r] + mx[r % 2]);
            mx[r % 2] = max(mx[r % 2], -pref_even[r] + pref_odd[r]);
        }
        cout << best << '\n';
    }
    return 0;
}