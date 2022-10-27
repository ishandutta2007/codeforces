#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

void solve() {
    string s;
    int n, k;
    cin >> n >> k >> s;
    if (k == 0) {
        cout << "1\n";
        return;
    }
    string rs = s;
    reverse(rs.begin(), rs.end());
    cout << 1 + ((s + rs) != (rs + s)) << '\n';
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