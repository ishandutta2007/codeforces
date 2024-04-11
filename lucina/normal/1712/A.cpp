#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, k;
int a[nax];

void solve() {
    cin >> n >> k;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }
    int ans = 0;

    for (int i = 1 ; i <= k ; ++ i) {
        if (a[i] > k) {
            ans += 1;
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