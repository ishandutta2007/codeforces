#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

template<typename Fun>
struct y_combinator {
    const Fun fun;

    y_combinator(const Fun&& fun) : fun(forward<const Fun>(fun)) {}

    template<typename... Tail>
    decltype(auto) operator()(Tail&&... tail) const {
        return fun(ref(*this), forward<Tail>(tail)...);
    }
};

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (auto c : s) cnt[c - 'a']++;
    for (int i = 0; i < len(s); i++) {
        if (cnt[s[i] - 'a'] == 1) {
            cout << s.substr(i) << '\n';
            return;
        }
        cnt[s[i] - 'a']--;
    }
    assert(false);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests = 1;
    cin >> tests;
    while (tests--) solve();
}