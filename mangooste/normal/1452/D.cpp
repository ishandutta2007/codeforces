#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <set>
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

const int MOD = 998244353;

int power(int a, int b) {
    if (b == 0) return 1;
    if (b % 2) return (ll) a * power(a, b - 1) % MOD;
    return power((ll) a * a % MOD, b / 2);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> dp(n, 0);
    array<int, 2> sums{ 0, 0 };
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) dp[i] = 1;
        dp[i] += sums[(i + 1) % 2];
        if (dp[i] >= MOD) dp[i] -= MOD;
        sums[i % 2] += dp[i];
        if (sums[i % 2] >= MOD) sums[i % 2] -= MOD;
    }

    int ans = dp.back();
    int p2 = 1;
    for (int i = 0; i < n; i++) {
        p2 = (ll) p2 * 2 % MOD;
    }
    dbg(p2);
    cout << (ll) ans * power(p2, MOD - 2) % MOD << '\n';
}