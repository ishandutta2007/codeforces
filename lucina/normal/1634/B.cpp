#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int64_t a[nax];
int64_t x, y;

void solve() {
    cin >> n >> x >> y;
    int64_t u = 0;
    for (int i = 1 ; i <= n ; ++ i) {
         cin >> a[i];
         u += (a[i] % 2);
    }
    u %= 2;
    if ((y + x + u) % 2 == 0) {
        cout << "Alice\n";
    } else cout << "Bob\n";
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