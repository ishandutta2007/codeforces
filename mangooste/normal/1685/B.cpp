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
    int a, b, c, d;
    string s;
    cin >> a >> b >> c >> d >> s;
    assert(len(s) == a + b + 2 * (c + d));

    if (count(all(s), 'A') - c - d != a || count(all(s), 'B') - c - d != b) {
        cout << "NO\n";
        return;
    }

    array<vector<int>, 2> lens;
    for (int i = 0, j = 0; i < len(s) - 1; i = j) {
        if (s[i] == s[i + 1]) {
            j = i + 1;
            continue;
        }
        while (j < len(s) && ((j & 1) == (i & 1) ? (s[i] == s[j]) : (s[i + 1] == s[j]))) {
            j++;
        }
        lens[s[i] == 'B'].push_back(j - i);
    }

    for (int i : {0, 1}) sort(all(lens[i]));
    for (int parity : {0, 1}) {
        for (int rot = 0; rot < 2; rot++, swap(c, d), swap(lens[0], lens[1])) {
            for (auto &x : lens[0]) {
                if (x % 2 != parity) continue;
                while (c > 0 && x >= 2) {
                    c--;
                    x -= 2;
                }
                d -= min(d, (x - 1) / 2);
            }
        }
    }
    cout << (c == 0 && d == 0 ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}