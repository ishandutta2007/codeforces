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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n; cin >> m >> n;
    vector<vector<int>> already;
    bool ok = true;
    for (int i = 0; i < m; i++) {
        int sz; cin >> sz;
        vector<int> indexes(sz);
        for (auto &x : indexes) cin >> x;
        sort(all(indexes));

        for (int j = 0; j < i; j++) {
            bool any = false;
            for (auto x : indexes) {
                any |= binary_search(all(already[j]), x);
            }
            ok &= any;
        }
        already.push_back(indexes);
    }
    cout << (ok ? "possible\n" : "impossible\n");
}