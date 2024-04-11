#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int64_t k;
int n;
int64_t a[nax];
int64_t udiv(int64_t a, int64_t b) {
    return (a + b - 1) / b;
}

void solve() {
    cin >> n >> k;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int64_t ans = 1e18;
    int64_t keep = 0;
    /// keep prefix of length X unchanged
    for (int i = 1 ; i <= n ; ++ i) {
        keep += a[i];
        int64_t bar = 1ll * (n - i) * a[1];
        int64_t need = (keep + bar) - k;
        int64_t g = max(int64_t(0), udiv(need, (n - (i - 1))));
        ans = min(ans, n - i + g);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ; ) {
        solve();
    }

}