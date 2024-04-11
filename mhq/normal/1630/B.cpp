#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, k;
const int maxN = 2e5 + 10;
int cnt[maxN];
int a[maxN];
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cnt[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int best = 1e9;
    int x = -1;
    int y = -1;
    int r = 0;
    int tot = 0;
    for (int l = 1; l <= n; l++) {
        while (r + 1 <= n && tot - (n - tot) < k) {
            tot += cnt[r + 1];
            r++;
        }
        if (tot - (n - tot) < k) break;
        if (r - l < best) {
            x = l;
            y = r;
            best = r - l;
        }
        assert(l <= r);
        tot -= cnt[l];
    }
    cout << x << " " << y << '\n';
    int cur_l = 1;
    int bal = 0;
    int need = k;
    for (int i = 1; i <= n; i++) {
        if (x <= a[i] && a[i] <= y) {
            bal++;
        }
        else {
            bal--;
        }
        if ((bal == 1 && need > 1) || (i == n)) {
            cout << cur_l << " " << i << '\n';
            need--;
            bal = 0;
            cur_l = i + 1;
        }
    }

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