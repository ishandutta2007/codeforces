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

const int N = 5001;
int dp[N][N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    string a; cin >> a;
    string b; cin >> b;
    a.insert(a.begin(), 0);
    b.insert(b.begin(), 0);

    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j] - 1, dp[i][j - 1] - 1);
            if (a[i] == b[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
            dp[i][j] = max(dp[i][j], 0);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
}