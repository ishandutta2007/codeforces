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
    string s;
    cin >> s;
    int n = len(s);
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') pos.push_back(i);
    }

    if (n & 1) {
        cout << "NO\n";
        return;
    }

    auto good = [&](const string &s) {
        int balance = 0;
        for (auto c : s) {
            balance += c == '(' ? 1 : -1;
            if (balance < 0) return false;
        }
        assert(balance == 0);
        return true;
    };

    int open = n / 2 - count(all(s), '(');
    if (open < 0 || open > len(pos)) {
        cout << "NO\n";
        return;
    }

    auto first = s;
    for (int i = 0; i < open; i++) {
        first[pos[i]] = '(';
    }
    for (int i = open; i < len(pos); i++) {
        first[pos[i]] = ')';
    }
    assert(good(first));

    if (open == 0 || open == len(pos)) {
        cout << "YES\n";
        return;
    }
    auto second = first;
    swap(second[pos[open]], second[pos[open - 1]]);
    cout << (good(second) ? "NO" : "YES") << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}