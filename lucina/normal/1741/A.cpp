#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

int con(string s) {
    if (s[0] == 'M') return 1000;
    if (s.back() == 'S') {
        return -s.size();
    }
    return s.size() + 2000;
}

void solve() {
    string s, t;
    cin >> s >> t;
    int u = con(s), v = con(t);
    if (u == v) cout << "=\n";
    else cout << (u < v ? "<\n" : ">\n");
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}