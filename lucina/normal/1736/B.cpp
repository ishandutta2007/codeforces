#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int64_t b[nax];
int a[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }
    a[0] = a[n + 1] = 1;

    for (int i = 1 ; i <= n + 1 ; ++ i) {
        b[i] = lcm(a[i], a[i - 1]);
    }
    for (int i = 1 ; i <= n ; ++ i) {
        if (gcd(b[i], b[i + 1]) != a[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}