// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/1497/D

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
const int MAXN = 5005;

int t;
int n;
int tag[MAXN];
int s[MAXN];
ll dp[MAXN];
pll pmx[MAXN][2], nmx[MAXN][2];
ll odp[MAXN], na[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        REP (i, 1, n + 1) {
            cin >> tag[i];
        }
        REP (i, 1, n + 1) {
            cin >> s[i];
        }
        REP (i, 0, n + 5) {
            dp[i] = -LINF;
            pmx[i][0] = pmx[i][1] = {-LINF, -1};
            nmx[i][0] = nmx[i][1] = {-LINF, -1};
            odp[i] = na[i] = -LINF;
        }
        ll ans = 0;
        REP (i, 1, n + 1) {
            REP (j, 0, n + 5) {
                dp[j] = -LINF;
            }
            dp[i] = 0;
            cerr << i << '\n';
            REP (j, 1, i + 1) {
                if (tag[j] == tag[i]) continue;
                REP (k, 0, 2) {
                    if (pmx[j + 1][k].SE == -1 || 
                            tag[j] == tag[pmx[j + 1][k].SE]) continue;
                    mxto(dp[j], pmx[j + 1][k].FI - s[j] + abs(s[j] - s[i]));
                }
                REP (k, 0, 2) {
                    if (nmx[j + 1][k].SE == -1 || 
                            tag[j] == tag[nmx[j + 1][k].SE]) continue;
                    mxto(dp[j], nmx[j + 1][k].FI + s[j] + abs(s[j] - s[i]));
                }
                REP (k, 0, 2) {
                    if (odp[j] == -LINF) {
                        continue;
                    }
                    mxto(dp[j], odp[j] + abs(s[j] - s[i]));
                }
                mxto(ans, dp[j]);
                cerr << ' ' << j << ' ' << dp[j] << '\n';
            }
            REP (j, 1, i + 1) {
                mxto(odp[i], dp[j]);
            }
            /*
            REP (k, 0, 2) {
                if (pmx[0][k].SE == -1 || 
                        tag[i] == tag[pmx[0][k].SE]) continue;
                mxto(dp[pmx[0][k].SE], pmx[0][k].FI - s[i]);
                cerr << ' ' << pmx[0][k].SE << ' ' << dp[pmx[0][k].SE] << '\n';
            }
            REP (k, 0, 2) {
                if (nmx[0][k].SE == -1 || 
                        tag[i] == tag[nmx[0][k].SE]) continue;
                mxto(dp[nmx[0][k].SE], nmx[0][k].FI + s[i]);
                cerr << ' ' << pmx[0][k].SE << ' ' << dp[pmx[0][k].SE] << '\n';
            }
            */
            RREP (j, i, 0) {
                REP (k, 0, 2) {
                    if (pmx[j + 1][k].SE == -1) continue;
                    if (pmx[j][0] < pmx[j + 1][k]) {
                        if (pmx[j][0].SE != -1 && tag[pmx[j][0].SE] != tag[i]) {
                            pmx[j][1] = pmx[j][0];
                        }
                        pmx[j][0] = pmx[j + 1][k];
                    } else if (pmx[j][1] < pmx[j + 1][k] && 
                            tag[pmx[j + 1][k].SE] != tag[pmx[j][0].SE]) {
                        pmx[j][1] = pmx[j + 1][k];
                    }
                }
                if (dp[j] == -LINF) {
                    continue;
                }
                dp[j] += s[i];
                if (pmx[j][0].FI < dp[j]) {
                    if (pmx[j][0].SE != -1 && tag[pmx[j][0].SE] != tag[i]) {
                        pmx[j][1] = pmx[j][0];
                    }
                    pmx[j][0] = {dp[j], i};
                } else if (pmx[j][1].FI < dp[j] && tag[i] != tag[pmx[j][0].SE]) {
                    pmx[j][1] = {dp[j], i};
                }
                dp[j] -= s[i];
            }
            RREP (j, i, 0) {
                REP (k, 0, 2) {
                    if (nmx[j + 1][k].SE == -1) continue;
                    if (nmx[j][0] < nmx[j + 1][k]) {
                        if (nmx[j][0].SE != -1 && tag[nmx[j][0].SE] != tag[i]) {
                            nmx[j][1] = nmx[j][0];
                        }
                        nmx[j][0] = nmx[j + 1][k];
                    } else if (nmx[j][1] < nmx[j + 1][k] && 
                            tag[nmx[j + 1][k].SE] != tag[nmx[j][0].SE]) {
                        nmx[j][1] = nmx[j + 1][k];
                    }
                }
                if (dp[j] == -LINF) {
                    continue;
                }
                dp[j] -= s[i];
                if (nmx[j][0].FI < dp[j]) {
                    if (nmx[j][0].SE != -1 && tag[nmx[j][0].SE] != tag[i]) {
                        nmx[j][1] = nmx[j][0];
                    }
                    nmx[j][0] = {dp[j], i};
                } else if (nmx[j][1].FI < dp[j] && tag[i] != tag[nmx[j][0].SE]) {
                    nmx[j][1] = {dp[j], i};
                }
                dp[j] += s[i];
            }
        }
        REP (j, 1, n + 1) {
            REP (k, 0, 2) {
                if (pmx[j + 1][k].SE == -1 || 
                        tag[j] == tag[pmx[j + 1][k].SE]) continue;
                mxto(ans, pmx[j + 1][k].FI - s[j]);
            }
            REP (k, 0, 2) {
                if (nmx[j + 1][k].SE == -1 || 
                        tag[j] == tag[nmx[j + 1][k].SE]) continue;
                mxto(ans, nmx[j + 1][k].FI + s[j]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}