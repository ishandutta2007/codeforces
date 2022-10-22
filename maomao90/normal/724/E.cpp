// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/724/E

// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

#define INF 1000000005
#define LINF 1000000000000000005ll
#define MAXN 10005

int n, c;
int p[MAXN], s[MAXN];
ll dp[2][MAXN];
ll ans;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n >> c;
    REP (i, 0, n) {
        cin >> p[i];
    }
    REP (i, 0, n) {
        cin >> s[i];
    }
    int prv = 0, cur = 1;
    REP (j, 1, n + 1) {
        dp[cur][j] = LINF;
    }
    REP (i, 0, n) {
        swap(prv, cur);
        REP (j, 0, n + 1) {
            dp[cur][j] = LINF;
            mnto(dp[cur][j], dp[prv][j] + p[i] + (ll) c * j);
            if (j > 0) {
                mnto(dp[cur][j], dp[prv][j - 1] + s[i]);
            } else {
                mnto(dp[cur][j], dp[prv][j] + p[i] + s[i]);
            }
        }
    }
    ans = LINF;
    REP (j, 0, n + 1) {
        mnto(ans, dp[cur][j]);
    }
    cout << ans << '\n';
    return 0;
}