#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];
int dp[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        a[i] ^= a[i - 1];
    }

    map <int, int> where;
    where[0] = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        dp[i] = dp[i - 1];
        if (where.count(a[i])) {
            dp[i] = max(dp[i], dp[where[a[i]]] + 1);
        }
        where[a[i]] = i;
    }
    cout << n - dp[n] << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ; ) {
        solve();
    }
}