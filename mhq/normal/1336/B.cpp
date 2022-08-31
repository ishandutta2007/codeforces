#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll sq(ll x) {
    return x * x;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        vector < int > a[3];
        for (int i = 0; i < 3; i++) {
            int sz;
            cin >> sz;
            a[i].resize(sz);
        }
        for (int i = 0; i < 3; i++) {
            for (int& v : a[i]) cin >> v;
        }
        ll best = 5e18;
        for (int i = 0; i < 3; i++) sort(a[i].begin(), a[i].end());
        for (int it = 0; it < 3; it++) {
            swap(a[0], a[it]);
            for (int r = 0; r < 2; r++) {
                swap(a[1], a[2]);
                for (int v : a[0]) {
                    int p = lower_bound(a[1].begin(), a[1].end(), v) - a[1].begin();
                    if (p == a[1].size()) continue;
                    p = a[1][p];
                    if (a[2][0] > v) continue;
                    int t = upper_bound(a[2].begin(), a[2].end(), v) - a[2].begin();
                    assert(t != 0);
                    t -= 1;
                    t = a[2][t];
                    best = min(best, sq(p - t) + sq(p - v) + sq(t - v));
                }
            }
        }
        cout << best << '\n';
    }
    return 0;
}