#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n;

void solve() {
    cin >> n;
    if (n % 2) {
        cout << "0\n";
        return;
    }
    int64_t ans = 1;
    for (int j = 1 ; j <= n / 2 ; ++ j) {
        ans = ans * j % MOD;
    }
    cout << ans * ans % MOD << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    
    for (cin >> T ; T -- ;) {
        solve();
    }
}