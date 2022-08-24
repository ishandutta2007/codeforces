#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m, k;
const int maxN = 3505;
int a[maxN];
void solve() {
    cin >> n >> m >> k;
    k = min(k, m - 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int mx = 0;
    for (int c1 = 0; c1 <= k; c1++) {
        int c2 = k - c1;
        int mn = 1e9 + 100;
        int len = n - m + 1;
        for (int l = 1; l <= n; l++) {
            int r = l + len - 1;
            if (r > n - c2) continue;
            if (l < 1 + c1) continue;
            mn = min(mn, max(a[l], a[r]));
        }
        mx = max(mx, mn);
    }
    cout << mx << '\n';
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