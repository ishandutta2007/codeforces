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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    ll sum = accumulate(all(a), 0ll);
    map<ll, ll> cnt;
    for (auto x : a) cnt[x]++;
    map<ll, ll> cur_cnt;
    cur_cnt[sum]++;
    while (!cur_cnt.empty()) {
        auto it = prev(cur_cnt.end());
        ll value = it->first;
        ll cur_c = it->second;
        cur_cnt.erase(it);
        if (cnt[value] > cur_c) {
            cout << "NO\n";
            return;
        }
        cur_c -= cnt[value];
        cnt[value] = 0;
        if (value == 1 && cur_c) {
            cout << "NO\n";
            return;
        }
        if (cur_c == 0) continue;
        cur_cnt[value / 2] += cur_c;
        cur_cnt[(value + 1) / 2] += cur_c;
    }
    for (auto [_, c] : cnt) {
        if (c != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests = 1;
    cin >> tests;
    while (tests--) solve();
}