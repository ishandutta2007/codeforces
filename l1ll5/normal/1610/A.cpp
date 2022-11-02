#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 200000 + 5;
void solve() {
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << "0\n";
    }
    else if (n == 1 || m == 1) {
        cout << "1\n";
    }
    else {
        cout << "2\n";
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}