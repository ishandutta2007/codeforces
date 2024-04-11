#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int64_t x;
int64_t a[nax];

void solve() {
    cin >> n >> x;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int64_t ans = 0;
    int64_t from = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        a[i] += a[i - 1];
        int64_t b = a[i];
        /**
            how many day will you be able to buy i-th shop
        */
        /// b, b + 1, b + 2, ...
        /// b, b + i, b + 2 * i
        /// b + k * i <= x
        if (x < b) continue;
        ans += max(0ll, 1 + (x - b) / i);
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