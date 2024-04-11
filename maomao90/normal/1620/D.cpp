// time-limit: 2000
// problem-url: https://codeforces.com/contest/1620/problem/D

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

#ifndef DEBUG
#define cerr if (0) cerr
#endif

#define INF 1000000005
#define LINF 1000000000000000005ll
#define MAXN 200005

int t;
int n;
int a[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        REP (i, 0, n) {
            cin >> a[i];
        }
        sort(a, a + n, greater<int>());
        int ans = INF;
        int cnt = (a[0] - 1) / 3 + 1;
        REP (i, 0, 4) {
            REP (j, 0, 4) {
                REP (k, cnt - 2, cnt + 1) {
                    bool gpos = 1;
                    REP (x, 0, n) {
                        bool pos = 0;
                        REP (i1, 0, i + 1) {
                            REP (j1, 0, j + 1) {
                                int rem = a[x] - i1 - j1 * 2;
                                if (rem < 0 || rem % 3 != 0) continue;
                                if (rem / 3 <= k) {
                                    pos = 1;
                                    break;
                                }
                            }
                            if (pos) {
                                break;
                            }
                        }
                        if (!pos) {
                            gpos = 0;
                            break;
                        }
                    }
                    if (gpos) {
                        mnto(ans, i + j + k);
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}