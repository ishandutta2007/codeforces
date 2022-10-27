#include<bits/stdc++.h>
using namespace std;
string s[150];
int n, k;
int64_t a[150];

void solve() {
    cin >> n >> k;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    sort(a + 1, a + 1 + n, greater<int>());
    int64_t ans = 0;
    for (int i = 1 ; i <= k ; ++ i) {
        ans += a[i + k] / a[i];
    }
    for (int i = k + k + 1 ; i <= n ; ++ i)
        ans += a[i];
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}