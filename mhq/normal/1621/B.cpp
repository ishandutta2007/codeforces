#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
ll l[maxN], r[maxN], c[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        ll best_l = 1e18;
        ll best_r = 1e18;
        ll best_two = 1e18;
        ll min_l = 1e18;
        ll max_r = -1e18;
        for (int i = 1; i <= n; i++) {
            cin >> l[i] >> r[i] >> c[i];
            if (min_l > l[i]) {
                min_l = l[i];
                best_l = c[i];
                best_two = 1e18;
            }
            if (max_r < r[i]) {
                max_r = r[i];
                best_r = c[i];
                best_two = 1e18;
            }
            if (min_l == l[i]) best_l = min(best_l, c[i]);
            if (max_r == r[i]) best_r = min(best_r, c[i]);
            if (l[i] == min_l && r[i] == max_r) best_two = min(best_two, c[i]);
            cout << min(best_two, best_l + best_r) << '\n';
        }

    }
    return 0;
}