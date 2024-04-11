#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];
int b[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }

    int y = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> b[i];
        y += (a[i] != b[i]);
    }
    y = min(y, abs(accumulate(a + 1, a + 1 + n, 0) - accumulate(b + 1, b + 1 + n, 0)) + 1);
    cout << y << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}