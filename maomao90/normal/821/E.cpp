// time-limit: 2000
// problem-url: https://codeforces.com/contest/821/problem/E

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
#define MOD 1000000007
#define MAXC 16
#define MAXL 61

int n;
ll k;
ll a[MAXN], b[MAXN];
int c[MAXN];
ll ans[MAXC], nans[MAXC];
ll grid[MAXL][MAXC][MAXC];
ll res[MAXC][MAXC], nres[MAXC][MAXC];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n >> k;
    REP (i, 0, n) {
        cin >> a[i] >> b[i] >> c[i];
        mnto(b[i], k);
    }
    ans[0] = 1;
    REP (i, 0, n) {
        memset(grid, 0, sizeof grid);
        REP (i, 0, MAXC) {
            if (i - 1 >= 0) {
                grid[0][i - 1][i] = 1;
            }
            grid[0][i][i] = 1;
            if (i + 1 < MAXC) {
                grid[0][i + 1][i] = 1;
            }
        }
        REP (j, c[i] + 1, MAXC) {
            REP (k, 0, MAXC) {
                grid[0][j][k] = 0;
            }
        }
        REP (j, 0, MAXC) {
            REP (k, c[i] + 1, MAXC) {
                grid[0][j][k] = 0;
            }
        }
        REP (z, 1, MAXL) {
            REP (i, 0, MAXC) {
                REP (j, 0, MAXC) {
                    REP (k, 0, MAXC) {
                        grid[z][i][j] += grid[z - 1][i][k] * grid[z - 1][k][j] % MOD;
                        if (grid[z][i][j] >= MOD) {
                            grid[z][i][j] -= MOD;
                        }
                    }
                }
            }
            REP (j, c[i] + 1, MAXC) {
                REP (k, 0, MAXC) {
                    grid[z][j][k] = 0;
                }
            }
            REP (j, 0, MAXC) {
                REP (k, c[i] + 1, MAXC) {
                    grid[z][j][k] = 0;
                }
            }
        }
        REP (i, 0, MAXC) {
            REP (j, 0, MAXC) {
                cerr << grid[0][i][j] << ' ';
            }
            cerr << '\n';
        }
        cerr << '\n';
        REP (j, c[i] + 1, MAXC) {
            ans[j] = 0;
        }
        REP (j, 0, MAXC) {
            cerr << ans[j] << ' ';
        }
        cerr << '\n';
        ll l = b[i] - a[i];
        REP (i, 0, MAXC) {
            REP (j, 0, MAXC) {
                res[i][j] = 0;
            }
            res[i][i] = 1;
        }
        int b = 0;
        while (l) {
            if (l & 1) {
                memset(nres, 0, sizeof nres);
                REP (i, 0, MAXC) {
                    REP (j, 0, MAXC) {
                        REP (k, 0, MAXC) {
                            nres[i][j] += res[i][k] * grid[b][k][j] % MOD;
                            if (nres[i][j] >= MOD) {
                                nres[i][j] -= MOD;
                            }
                        }
                    }
                }
                swap(nres, res);
                REP (i, 0, MAXC) {
                    REP (j, 0, MAXC) {
                        cerr << res[i][j] << ' ';
                    }
                    cerr << '\n';
                }
                cerr << '\n';
            }
            b++;
            l >>= 1;
        }
        cerr << '\n';
        memset(nans, 0, sizeof nans);
        REP (i, 0, MAXC) {
            REP (j, 0, MAXC) {
                nans[i] += ans[j] * res[j][i] % MOD;
                if (nans[i] >= MOD) {
                    nans[i] -= MOD;
                }
            }
        }
        swap(ans, nans);
    }
    cout << ans[0] << '\n';
    return 0;
}