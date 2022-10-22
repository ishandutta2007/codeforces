// time-limit: 2000
// problem-url: https://codeforces.com/contest/842/problem/D

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
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

#define INF 1000000005
#define LINF 1000000000000000005ll
#define MAXN 600005
#define MAXL 20

int n, m;
bool dp[MAXL][MAXN];

int main() {
    cin >> n >> m;
    int mx = 0;
    REP (i, 0, n) {
        int a; cin >> a;
        dp[0][a] = 1;
        mxto(mx, a);
    }
    REP (k, 1, MAXL) {
        REP (i, 0, mx + 1) {
            dp[k][i] = dp[k - 1][i] && dp[k - 1][i ^ (1 << k - 1)];
        }
    }
    int px = 0;
    while (m--) {
        int x; cin >> x;
        px ^= x;
        int cur = 0;
        int ans = 0;
        RREP (k, MAXL - 1, 0) {
            if (px >> k & 1) {
                cur ^= 1 << k;
            }
            if (dp[k][cur]) {
                ans += 1 << k;
                cur ^= 1 << k;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}