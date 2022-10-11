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

inline void fix(vector<pair<int, string>> &ops, int k) {
//    dbg(ops);
//    dbg("fixing", ops, k);
    int already = 0;
    for (int i = 0; i < sz(ops); i++) {
        already += ops[i].first * sz(ops[i].second);
//        dbg(already);
        if (already >= k) {
            int prSz = sz(ops);
            for (int j = i + 1; j < prSz; j++) {
                ops.pop_back();
            }
            auto [cnt, s] = ops.back();
            ops.pop_back();

            already -= cnt * sz(s);
            k -= already;
            assert(k);
            if (k / sz(s)) ops.emplace_back(k / sz(s), s);
            k %= sz(s);
            if (k) ops.emplace_back(1, s.substr(0, k));
            return;
        }
    }
    assert(false);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;
    if (k > 4 * n * m - 2 * n - 2 * m) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<pair<int, string>> ops;

    if (n == 1) {
        ops.emplace_back(min(k, m - 1), "R");
        k -= min(k, m - 1);
        if (k) ops.emplace_back(k, "L");
    } else if (m == 1) {
        ops.emplace_back(min(k, n - 1), "D");
        k -= min(k, n - 1);
        if (k) ops.emplace_back(k, "U");
    } else {
        ops.emplace_back(m - 1, "DRU");
        ops.emplace_back(m - 1, "L");
        ops.emplace_back(m - 1, "R");
        ops.emplace_back(1, "D");
        ops.emplace_back(m - 1, "L");
        for (int i = 2; i < n; i++) {
            ops.emplace_back(m - 1, "DRU");
            ops.emplace_back(1, "D");
            ops.emplace_back(m - 1, "L");
        }
        ops.emplace_back(n - 1, "U");
        fix(ops, k);
    }

    cout << sz(ops) << '\n';
    for (auto [cnt, s] : ops) {
        cout << cnt << ' ' << s << '\n';
    }
}