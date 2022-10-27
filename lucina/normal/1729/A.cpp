#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int x = a - 1;
    int y = abs(b - c) + c - 1;
    if (x == y) {
        cout << 3 << '\n';
    } else {
        cout << 1 + (x > y) << '\n';
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }

}