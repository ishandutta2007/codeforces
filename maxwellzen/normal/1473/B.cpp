#include <bits/stdc++.h>
#include <numeric>

using namespace std;

void solve() {
    string a, b;
    cin >> a;
    cin >> b;
    int lo = a.length();
    while (lo % b.length() != 0) lo += a.length();
    string ta="", tb="";
    for (int i = 0; i < lo; i += a.length()) {
        ta += a;
    }
    for (int i = 0; i < lo; i += b.length()) {
        tb += b;
    }
    if (ta==tb) cout << ta << "\n";
    else cout << -1 << "\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}