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
    string s;
    cin >> n >> s;
    if (is_sorted(all(s))) {
        cout << "0\n";
        return;
    }
    cout << "1\n";

    int pref_ones = 0;
    int suf_zeroes = count(all(s), '0');
    for (int pos = 0; pos < n; pos++) {
        pref_ones += s[pos] == '1';
        suf_zeroes -= s[pos] == '0';
        if (pref_ones == suf_zeroes) {
            cout << pref_ones * 2;
            for (int i = 0; i <= pos; i++) {
                if (s[i] == '1') cout << ' ' << i + 1;
            }
            for (int i = pos + 1; i < n; i++) {
                if (s[i] == '0') cout << ' ' << i + 1;
            }
            cout << '\n';
            return;
        }
    }
    assert(false);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}