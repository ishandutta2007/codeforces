#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, m, x, y, d;

void solve() {
    cin >> n >> m >> x >> y >> d;
    if ((x - 1 > d && m - y > d) || (y - 1 > d && n - x > d)) {
        cout << n + m - 2 << '\n';
    } else cout << "-1\n";

}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;


    for (cin >> T ; T -- ;) {
        solve();
    }
}