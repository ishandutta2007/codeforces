#include<bits/stdc++.h>
using namespace std;
int n;

void solve() {
    cin >> n;

    int bar = sqrt(n);
    int ans = INT_MAX;

    for (int j = - 100 ; j <= 100 ; ++ j) {
        if (bar + j <= 0) continue;
        int cur = bar + j - 1;
        int v = bar + j;
        cur += (n + v - 1) / v;
        ans = min(ans, cur);
    }
    cout << ans - 1 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}