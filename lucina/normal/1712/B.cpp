#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, k;
int a[nax];

void solve() {
    cin >> n;
    iota(a + 1, a + 1 + n, 1);
    for (int i = n ; i > 1 ; i -= 2) {
        swap(a[i], a[i - 1]);
    }
    for (int i = 1  ; i <= n ; ++ i) cout << a[i] << ' ';
    cout << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}