#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3e5 + 10;
int c[maxN];
int k[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> k[i];
        }
        sort(k + 1, k + n + 1);
        vector<int> ff;
        for (int i = 1; i <= m; i++) {
            cin >> c[i];
            ff.emplace_back(c[i]);
        }
        for (int i = 1; i <= n; i++) {
            ff.emplace_back(c[k[i]]);
        }
        sort(ff.begin(), ff.end());
        ll ans = 0;
        for (int i = 0; i < n; i++) ans += ff[i];
        cout << ans << '\n';
//        int l = 0;
//        int r = min(n, m) + 1;
//        while (r - l > 1) {
//            int mid = (l + r) / 2;
//            bool ok = true;
//            for (int j = n - mid + 1; j <= n; j++) {
//                if (k[j] < j - (n - mid)) {
//                    ok = false;
//                }
//            }
//            if (ok) l = mid;
//            else r = mid;
//        }
//        cout << l << " " << n << endl;
//        ll tot = 0;
//        for (int j = 1; j <= n - l; j++) {
//            tot += c[k[j]];
//        }
//        for (int j = n - l + 1; j <= n; j++) {
//            tot += c[min(j - (n - l), k[j])];
//        }
//        cout << tot << '\n';
    }
    return 0;
}