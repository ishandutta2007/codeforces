#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int a[nax];
int mx[nax];

void solve() {
    int n;
    cin >> n;
    fill(mx, mx + 1050, 0);
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        mx[a[i]] = max(mx[a[i]], i);
    }
    int ans = -1;

    for (int i = 1 ; i <= 1000 ; ++ i)
    for (int j = 1 ; j <= i ; ++ j) {
        if (gcd(i, j) == 1) {
            if (mx[i] && mx[j]) {
                ans = max(ans, mx[i] + mx[j]);
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