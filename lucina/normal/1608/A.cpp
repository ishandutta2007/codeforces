#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
using ll = int64_t;

void solve() {
    int n;
    cin >> n;
    for (int i = 2 ; i <= n + 1 ; ++ i) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ; ) {
        solve();
    }
}