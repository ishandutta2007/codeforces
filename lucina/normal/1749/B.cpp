#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, m;
int b[nax];



void solve() {
    cin >> n;
    int64_t ans = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        int x;
        cin >> x;
        ans += x;
    }
    int mx = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        int b;
        cin >> b;
        ans += b;
        mx = max(mx, b);
    }
    cout << ans - mx << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}