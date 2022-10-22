// time-limit: 2000
// problem-url: https://codeforces.com/contest/1738/problem/C

// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
#include <bits/stdc++.h> 
using namespace std;

#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define RREP(i, s, e) for (int i = (s); i >= (e); i--)
template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
typedef long long ll;
typedef long double ld;
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define SZ(_a) (int) _a.size()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

const int INF = 1000000005;
const ll LINF = 1000000000000000005ll;
const int MAXN = 105;

int t;
int n;
int a[MAXN];
bool dp[MAXN][MAXN][2][2];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    dp[0][0][0][0] = 1;
    dp[0][0][0][1] = 0;
    dp[0][0][1][0] = 0;
    dp[0][0][1][1] = 1;
    REP (i, 0, MAXN) {
        REP (j, 0, MAXN) {
            if (i == 0 && j == 0) {
                continue;
            }
            REP (k, 0, 2) {
                REP (l, 0, 2) {
                    if (i > 0) {
                        dp[i][j][k][l] |= dp[i - 1][j][k ^ 1][l] ^ 1;
                    }
                    if (j > 0) {
                        dp[i][j][k][l] |= dp[i][j - 1][k ^ 1][l ^ (k == 0)] ^ 1;
                    }
                    cerr << i << ' ' << j << ' ' << k << ' ' << l << ": " << dp[i][j][k][l] << '\n';
                }
            }
        }
    }
    cin >> t;
    while (t--) {
        cin >> n;
        int x = 0, y = 0;
        REP (i, 0, n) {
            cin >> a[i];
            if (a[i] % 2 == 0) {
                x++;
            } else {
                y++;
            }
        }
        if (dp[x][y][0][0]) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
    return 0;
}