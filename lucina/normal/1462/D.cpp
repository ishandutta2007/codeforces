#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int a[nax];
int n;

void solve() {
    cin >> n;

    int sum = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        sum += a[i];
    }

    int ans = INT_MAX;

    for (int j = 1 ; j <= n ; ++ j) {
        if (sum % j == 0) {
            int tar = sum / j;
            int cur = 0;

            bool fail = false;

            for (int i = 1 ; i <= n ; ++ i) {
                cur += a[i];
                if (cur == tar) {
                    cur = 0;
                } else if (cur > tar) {
                    fail = true;
                    break;
                }
            }
            if (!fail && cur == 0) {

                ans = min(ans, n - j);
            }
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