#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n;
int64_t a, b;
int64_t x[nax];

void solve() {
    cin >> n >> a >> b;
    int64_t ans = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> x[i];
        ans += b * x[i];
    }
    int p = 0;
    for (int i = 2 ; i <= n ; ++ i) {
        if (a <= b * (n - i + 1)) {
            ans += a * (x[i - 1] - p);
            ans -= b * (x[i - 1] - p) * (n - i + 1);
            p = x[i - 1];
        }
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