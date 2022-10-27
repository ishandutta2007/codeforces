#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, k;
int64_t a[nax];
int64_t s[nax];
int64_t C(int64_t x) {
    return x * (x - 1) / 2;
}

void solve() {
    cin >> n >> k;
    int64_t sum = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    sum = s[n];
    int64_t ans;
    if (k <= n) {
        ans = 0;
        for (int i = 1 ; i + k - 1 <= n ; ++ i) {
            ans = max(ans, s[i + k - 1] - s[i - 1] + C(k));
        }
    } else {
        ans = s[n];
        for (int i = 1 ; i <= n ; ++ i)
            ans += k - i;
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
    Yay Div.1~ GL
    Lucina
*/