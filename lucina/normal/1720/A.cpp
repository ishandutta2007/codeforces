#include<bits/stdc++.h>
using namespace std;

void solve() {
    int64_t a, b, c, d;
    cin >> a >> b >> c >> d;
    a *= d, b *= c;
    if (a == b) cout << '0';
    else if (a == 0 || b == 0) cout << '1';
    else if (a % b == 0 || b % a == 0) cout << '1';
    else cout << '2';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}