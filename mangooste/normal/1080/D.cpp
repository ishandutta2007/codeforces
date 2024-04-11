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

    array<vector<ll>, 2> dp;
    for (int i = 0; i < 2; i++) {
        dp[i] = vector<ll>(41, 0);
    }
    dp[0][1] = 4;
    dp[1][1] = 2;
    for (int i = 2; i < 41; i++) {
        dp[0][i] = dp[0][i - 1] * 4;
        dp[1][i] = dp[1][i - 1] * 2;

        dp[0][i - 1] = (dp[0][i - 1] - 1) / 3;
        dp[1][i - 1] += dp[1][i - 2] - 1;
    }

    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;

        if (n > 31) {
            cout << "YES " << n - 1 << '\n';
        } else if (k > dp[0][n] || (n == 2 && k == 3)) {
            cout << "NO\n";
        } else {
            for (int i = 1; i <= n; i++) {
                if (k >= dp[1][i] && k <= dp[0][i] + dp[0][n - i] * ((1ll << i) - 1) * ((1ll << i) - 1)) {
                    cout << "YES " << n - i << '\n';
                    break;
                }
            }
        }
    }
}