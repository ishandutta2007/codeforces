#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

void solve() {
    int z;
    cin >> n >> z;
    int ans = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        ans = max(ans, a[i]);
        ans = max(ans, a[i] | z);
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
/**
    ....Global round....
*/