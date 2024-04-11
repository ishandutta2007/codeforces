#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

void solve() {
    int64_t m;
    cin >> m;
    int64_t x = 1;
    while (x * 10ll <= m) {
        x *= 10ll;
    }
    cout << m - x << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }

}