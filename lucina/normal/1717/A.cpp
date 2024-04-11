#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = n / 1 + 2 * (n / 2 + n / 3);
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }

}