#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    string s;
    cin >> s;
    vector<bool> occ(26);
    for (auto c : s) occ[c - 'a'] = true;

    for (int c1 = 0; c1 < 26; c1++) {
        if (!occ[c1]) continue;
        for (int c2 = c1 + 1; c2 < 26; c2++) {
            if (!occ[c2]) continue;
            int last = -1;
            for (int i = 0; i < len(s); i++) {
                if (s[i] - 'a' == c1) {
                    if (last == c1) {
                        cout << "NO\n";
                        return;
                    }
                    last = c1;
                } else if (s[i] - 'a' == c2) {
                    if (last == c2) {
                        cout << "NO\n";
                        return;
                    }
                    last = c2;
                }
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}