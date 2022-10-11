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
    sort(all(a));
    cout << a[n - 1] + a[n - 2] << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests = 1;
    cin >> tests;
    while (tests--) solve();
}