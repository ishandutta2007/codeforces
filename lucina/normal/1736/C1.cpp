#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int a[nax];
int n;


void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }
    int64_t ans = 0;

    for (int l = 1, r = 1 ; l <= n ; ++ l) {
        while (r + 1 <= n && a[r + 1] >= r + 1 - l + 1) r += 1;
        ans += r - l + 1;
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