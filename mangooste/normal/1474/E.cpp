#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> perm(n);
    iota(all(perm), 0);
    vector<pair<int, int>> ops;
    ll answer = 0;

    auto do_swap = [&](int i, int j) {
        assert(perm[i] == i);
        ops.emplace_back(i, j);
        answer += 1ll * (i - j) * (i - j);
        swap(perm[i], perm[j]);
    };

    do_swap(0, n - 1);
    for (int i = 1; i <= n - 1 - i; i++) {
        do_swap(i, n - 1);
        if (i != n - 1 - i)
            do_swap(n - 1 - i, 0);
    }

    cout << answer << '\n';
    for (auto x : perm)
        cout << x + 1 << ' ';

    cout << '\n' << len(ops) << '\n';
    reverse(all(ops));
    for (const auto &[i, j] : ops)
        cout << i + 1 << ' ' << j + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}