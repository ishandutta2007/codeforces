#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int p[nax];
int64_t l[nax];
int64_t r[nax];
int64_t sum[nax];

void solve() {
    cin >> n;
    for (int i = 2 ; i <= n ; ++ i)
        cin >> p[i];
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> l[i] >> r[i];
    }
    fill(sum, sum + 1 + n, 0);
    int ans = 0;
    for (int i = n ; i >= 1 ; -- i) {
        if (sum[i] < l[i]) {
            ans ++;
            sum[p[i]] += r[i];
        } else sum[p[i]] += min(sum[i], r[i]);

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
    CF800~ Rarely participated in 7xx round.
*/