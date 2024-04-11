#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

template<typename A, typename B> ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }
template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type> ostream& operator<<(ostream &out, A v) { out << '{'; string sep; for (const B &x : v) out << sep << x, sep = ", "; return out << '}'; }

void dbgPrint() { cerr << endl; }
template<typename A, typename... B> void dbgPrint(A a, B... b) { cerr << ' ' << a; dbgPrint(b...); }

#ifdef LOCAL
#define dbg(...) cerr << "line #" << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbgPrint(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define sz(a) int(a.size())
#define all(a) (a).begin(), (a).end()

int solve(vector<int> &a, int bit) {
    assert(bit >= 0);
    if (sz(a) <= 2) return 0;
    array<vector<int>, 2> els;
    for (auto x : a) {
        els[(x >> bit) % 2].push_back(x);
    }
    if (sz(els[0]) == 0 || sz(els[0]) == sz(a)) {
        return solve(a, bit - 1);
    }
    return min(solve(els[0], bit - 1) + sz(els[1]) - 1, solve(els[1], bit - 1) + sz(els[0]) - 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    cout << solve(a, 30) << '\n';
}