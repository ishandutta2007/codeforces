#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int m;
    cin >> m;
    vector<int> b(m);
    for (auto &x : b) cin >> x;

    int mx_a = *max_element(all(a));
    int mx_b = *max_element(all(b));
    if (mx_a >= mx_b) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }

    if (mx_b >= mx_a) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}