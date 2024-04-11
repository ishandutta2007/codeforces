#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        ll S = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            S += a[i];
            a[i] -= (n - i - 1);
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        ll best = S;
        for (int cnt_skip = 0; cnt_skip <= k; cnt_skip++) {
            best = min(best, S - (1LL * cnt_skip * (cnt_skip - 1)) / 2);
            if (cnt_skip < n) {
                S -= a[cnt_skip];
            }
        }
        cout << best << '\n';
    }
    return 0;
}