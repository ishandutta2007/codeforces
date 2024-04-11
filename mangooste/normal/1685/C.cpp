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
    string s;
    cin >> n >> s;
    n <<= 1;

    vector<int> balance(n + 1);
    auto build_balance = [&]() {
        for (int i = 0; i < n; i++) {
            balance[i + 1] = balance[i] + (s[i] == '(' ? 1 : -1);
        }
    };

    build_balance();
    if (*min_element(all(balance)) == 0) {
        cout << "0\n";
        return;
    }

    auto solve1 = [&]() -> pair<int, int> {
        int pos = 0;
        while (balance[pos] >= 0) pos++;
        int pos_pref = max_element(balance.begin(), balance.begin() + pos) - balance.begin();
        int max_pref = balance[pos_pref];

        pos = n;
        while (balance[pos] >= 0) pos--;
        int pos_suf = max_element(balance.begin() + pos + 1, balance.end()) - balance.begin();
        int max_suf = balance[pos_suf];

        int max_balance = *max_element(all(balance));
        if (max_pref + max_suf - max_balance < 0) return {-1, -1};
        return {pos_pref, pos_suf - 1};
    };

    auto [l, r] = solve1();
    if (l != -1) {
        cout << "1\n";
        cout << l + 1 << ' ' << r + 1 << '\n';
        return;
    }
    cout << "2\n";

    int pos_max = max_element(all(balance)) - balance.begin();
    reverse(s.begin(), s.begin() + pos_max);
    cout << 1 << ' ' << pos_max << '\n';

    build_balance();
    tie(l, r) = solve1();
    assert(l != -1);
    cout << l + 1 << ' ' << r + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}