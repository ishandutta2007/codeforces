#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "/home/Templates/debug.h"
#else
    #define dbg(...)
#endif // LOCAL

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int first = -1, last = -1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) continue;
        if (first == -1) first = i;
        last = i;
    }
    
    if (first == last) {
        cout << "0\n";
        return;
    }
    cout << max(1, last - first - 1) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}