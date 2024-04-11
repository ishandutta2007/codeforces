#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

void solve() {
    int n;
    cin >> n;
    if (n % 2) {
        cout << "-1\n";
    } else {

        int x = n >> 1;
        cout << x << ' ' << 0  << ' ' << 0 << '\n';
    }

}

int main() {
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}