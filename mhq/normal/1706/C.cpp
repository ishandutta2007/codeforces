#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
const int maxN = 1e5 + 10;
ll h[maxN];
ll val2[maxN];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    if (n % 2 == 1) {
        ll ans = 0;
        for (int i = 2; i < n; i += 2) {
            ans += max(0LL, max(h[i + 1], h[i - 1]) + 1 - h[i]);
        }
        cout << ans << '\n';
    }
    else {
        val2[n + 1] = 0;
        for (int i = n - 1; i >= 2; i -= 2) {
            val2[i] = val2[i + 2];
            val2[i] += max(0LL, max(h[i + 1], h[i - 1]) + 1 - h[i]);
        }
        ll best = val2[3];
        ll cur = 0;
        for (int i = 2; i <= n - 2; i += 2) {
            cur += max(0LL, max(h[i + 1], h[i - 1]) + 1 - h[i]);
            best = min(best, cur + val2[i + 3]);
        }
        cout << best << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}