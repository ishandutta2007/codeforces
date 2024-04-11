// time-limit: 2000
// problem-url: https://codeforces.com/contest/1673/problem/C

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
#define MAXN 40000
#define MAX 500
#define MOD 1000000007

int t;
int n;
int dp[MAXN + 5][MAX], sm[MAXN + 5][MAX];
vi pal;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    pal.pb(0);
    REP (i, 1, MAXN + 1) {
        string s = to_string(i);
        string rs = s;
        reverse(ALL(rs));
        if (rs == s) {
            pal.pb(i);
        }
    }
    dp[0][0] = 1;
    REP (j, 0, pal.size()) {
        sm[0][j] = 1;
    }
    REP (i, 1, MAXN + 1) {
        REP (j, 1, pal.size()) {
            if (i - pal[j] < 0) {
                break;
            }
            dp[i][j] += sm[i - pal[j]][j];
            if (dp[i][j] >= MOD) {
                dp[i][j] -= MOD;
            }
        }
        REP (j, 1, pal.size()) {
            sm[i][j] = dp[i][j];
            sm[i][j] += sm[i][j - 1];
            if (sm[i][j] >= MOD) {
                sm[i][j] -= MOD;
            }
        }
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cout << sm[n][pal.size() - 1] << '\n';
    }
    return 0;
}