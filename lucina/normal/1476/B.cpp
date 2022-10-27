#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int64_t n, k;
int64_t p[nax];

void solve() {
    cin >> n >> k;

    for (int i = 0 ; i < n ; ++ i)
        cin >> p[i];

    int64_t cur = p[0];
    int64_t ans = 0;

    for (int i = 1 ; i < n ; ++ i) {
        /**

                p[i] / cur <= k / 100
                100 * p[i] <= cur * k;
        */
        if (cur * k < 100 * p[i]) {
            int64_t bar = 100 * p[i];
            int64_t min_need = (bar + k - 1) / k;
            ans = max(ans, min_need - cur);
        }
        cur += p[i];
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}