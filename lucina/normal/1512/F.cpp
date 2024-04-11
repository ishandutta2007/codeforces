#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int x, y;
int n;
int64_t c;
int a[nax];
int b[nax];

void solve() {
    cin >> n >> c;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];

    for (int i = 1 ; i < n ; ++ i)
        cin >> b[i];
    int64_t ans = 1e17;
    int64_t cur = 0;
    int64_t many = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        int64_t res = max(0LL, c - cur);
        ans = min(ans, many + (res + a[i] - 1) / a[i]);
        if (i == n) break;
        res = max(0LL, b[i] - cur);
        int64_t bar = (res + a[i] - 1) / a[i];
        cur += bar * a[i];
        many += bar;
        cur -= b[i];
        many += 1;
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    cin >> T;
    for (int i = 1 ; i <= T ; ++ i) {
        solve();
    }

}