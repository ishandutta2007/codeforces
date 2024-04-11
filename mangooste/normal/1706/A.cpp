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
    int n, m;
    cin >> n >> m;
    string s(m, 'B');
    for (int i = 0; i < n; i++) {
        int pos;
        cin >> pos;
        pos--;
        int first = min(pos, m - 1 - pos);
        int second = max(pos, m - 1 - pos);
        if (s[first] == 'B') s[first] = 'A';
        else s[second] = 'A';
    }
    cout << s << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}