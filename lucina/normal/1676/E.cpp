#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;

int n, q;
int a[nax];


void solve() {
    cin >> n >> q;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    sort(a + 1, a + 1 + n, greater<int>());
    for (int i = 1 ; i <= n ; ++ i) {
        a[i] += a[i - 1];
    }
    while (q -- ) {
        int x;
        cin >> x;
        if (x > a[n]) cout << "-1\n";
        else cout << lower_bound(a + 1, a + 1 + n, x) - a << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
        //cout << (solve() ? "YES" : "NO") << '\n';
    }
}