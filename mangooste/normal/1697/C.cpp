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

void solve(int test_num) {
    int n;
    string s, t;
    cin >> n >> s >> t;

    array<vector<int>, 3> occ;
    for (int i = n - 1; i >= 0; i--) {
        occ[s[i] - 'a'].push_back(i);
    }
    for (auto c : t) {
        array<int, 3> pos;
        for (int i = 0; i < 3; i++) {
            pos[i] = occ[i].empty() ? n : occ[i].back();
        }

        bool fail = pos[c - 'a'] == n;
        if (c == 'a') {
            fail |= pos[1] < pos[0] || pos[2] < pos[0];
        } else if (c == 'b') {
            fail |= pos[2] < pos[1];
        } else {
            fail |= pos[0] < pos[2];
        }
        if (fail) {
            cout << "NO\n";
            return;
        }
        
        occ[c - 'a'].pop_back();
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}