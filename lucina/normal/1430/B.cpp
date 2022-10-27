#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, k;
int64_t a[nax];

void solve() {
    cin >> n >> k;

    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    sort(a + 1, a + 1 + n);

    for (int i = 1 ; i <= k ; ++ i) {
        a[n] += a[n - i];
        a[n - i] = 0;
    }
    cout << a[n] << '\n';
}



int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}