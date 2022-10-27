#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, k;

void solve() {
    cin >> n >> k;
    if (k == 1) {
        cout << "Yes\n";
        for (int i = 1 ; i <= n ; ++ i) cout << i << '\n';
        return;
    }
    if (n % 2 || n * k % 2) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    int odd = -1, even = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 0 ; j < k ; ++ j) {
            cout << (i % 2 ? (odd += 2) : (even += 2)) << ' ';
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    Alphacode!?
*/