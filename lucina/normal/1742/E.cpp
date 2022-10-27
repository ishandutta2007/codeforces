#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, q;
int a[nax];
int b[nax];
int64_t sum[nax];
void solve() {
    cin >> n >> q;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        b[i] = max(b[i - 1], a[i]);
        sum[i] = sum[i - 1] + a[i];
    }

    while (q --) {
        int k;
        cin >> k;
        int where = upper_bound(b + 1, b + 1 + n, k) - b - 1;
        cout << sum[where] << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}