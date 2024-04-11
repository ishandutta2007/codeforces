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
    #define dprint(...)
#endif // LOCAL

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s;
    getline(cin, s);
    int n = len(s);
    vector<array<int, 26>> go(n + 12);
    vector<int> p(n + 12);

    auto process = [&](int i) {
        p[i] = 0;
        if (i > 1) p[i] = go[p[i - 1]][s[i - 1] - 'a'];
        go[i].fill(0);
        for (int c = 0; c < 26; c++) {
            if (i == len(s)) continue;
            go[i][c] = s[i] - 'a' == c ? i + 1 : go[p[i]][c];
        }
    };
    for (int i = 0; i <= n; i++) process(i);

    int q;
    cin >> q >> ws;
    while (q--) {
        string t;
        getline(cin, t);
        int m = len(t);
        s += t;
        for (int i = n; i <= n + m; i++) {
            process(i);
            if (i > n) cout << p[i] << " \n"[i == n + m];
        }
        s.resize(n);
    }
}