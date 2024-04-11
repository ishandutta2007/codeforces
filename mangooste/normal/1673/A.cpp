#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    string s;
    cin >> s;
    int tot = 0;
    for (auto c : s) tot += c - 'a' + 1;
    if (len(s) == 1) {
        cout << "Bob " << tot << '\n';
    } else if (len(s) % 2 == 1) {
        cout << "Alice " << tot - 2 * min(s[0] - 'a', s.back() - 'a') - 2 << '\n';
    } else {
        cout << "Alice " << tot << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}