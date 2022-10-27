#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, m;

void solve() {
    cin >> n >> m;
    if (m > 1) {
        cout << 1ll * n * (m - 1) << '\n';
    } else {
        cout << n - 1 << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (T = 1 ; T -- ;) {
        solve();
    }
}