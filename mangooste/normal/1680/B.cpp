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
    int n, m;
    cin >> n >> m;
    int min_x = n, min_y = m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'R') {
                min_x = min(min_x, i);
                min_y = min(min_y, j);
            }
        }
    }
    cout << (s[min_x][min_y] == 'R' ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}