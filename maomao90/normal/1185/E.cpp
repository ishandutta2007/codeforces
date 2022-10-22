// time-limit: 4000
// problem-url: https://codeforces.com/contest/1185/problem/E

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

const int INF = 1000000005;
const ll LINF = 1000000000000000005ll;
const int MAXN = 2005;

int t;
int n, m;
string s[MAXN];
vector<tuple<int, int, int, int>> ans;

int main() {
    cin >> t;
    while (t--) {
        ans.clear();
        cin >> n >> m;
        REP (i, 0, n) {
            cin >> s[i];
        }
        bool start = 0;
        bool pos = 1;
        RREP (c, 'z', 'a') {
            int fi = -1, fj = -1;
            REP (i, 0, n) {
                REP (j, 0, m) {
                    if (s[i][j] == c) {
                        fi = i;
                        fj = j;
                        break;
                    }
                }
                if (fi != -1) {
                    break;
                }
            }
            if (fi == -1) {
                if (start) {
                    bool found = 0;
                    REP (i, 0, n) {
                        REP (j, 0, m) {
                            if (s[i][j] == '*') {
                                ans.pb({i, j, i, j});
                                found = 1;
                                break;
                            }
                        }
                        if (found) {
                            break;
                        }
                    }
                    if (!found) {
                        pos = 0;
                        break;
                    }
                }
                continue;
            }
            start = 1;
            int si = -1, sj = -1;
            REP (i, 0, n) {
                REP (j, 0, m) {
                    if (i == fi && j == fj) continue;
                    if (s[i][j] == c) {
                        si = i;
                        sj = j;
                        break;
                    }
                }
                if (si != -1) {
                    break;
                }
            }
            if (si == -1) {
                s[fi][fj] = '*';
                ans.pb({fi, fj, fi, fj});
                continue;
            }
            if (si != fi && sj != fj) {
                pos = 0;
                break;
            }
            if (si == fi) {
                int ej = m - 1;
                REP (j, fj, m) {
                    if (s[fi][j] != '*' && s[fi][j] != c) {
                        ej = j - 1;
                        break;
                    }
                }
                int sj = 0;
                RREP (j, fj, 0) {
                    if (s[fi][j] != '*' && s[fi][j] != c) {
                        sj = j + 1;
                        break;
                    }
                }
                REP (j, sj, ej + 1) {
                    s[fi][j] = '*';
                }
                ans.pb({fi, sj, fi, ej});
            } else {
                int ei = n - 1;
                REP (i, fi, n) {
                    if (s[i][fj] != '*' && s[i][fj] != c) {
                        ei = i - 1;
                        break;
                    }
                }
                int si = 0;
                RREP (i, fi, 0) {
                    if (s[i][fj] != '*' && s[i][fj] != c) {
                        si = i + 1;
                        break;
                    }
                }
                REP (i, si, ei + 1) {
                    s[i][fj] = '*';
                }
                ans.pb({si, fj, ei, fj});
            }
            fi = -1, fj = -1;
            REP (i, 0, n) {
                REP (j, 0, m) {
                    if (s[i][j] == c) {
                        fi = i;
                        fj = j;
                        break;
                    }
                }
                if (fi != -1) {
                    break;
                }
            }
            if (fi != -1) {
                pos = 0;
                break;
            }
        }
        if (!pos) {
            cout << "NO\n";
            continue;
        }
        reverse(ALL(ans));
        cout << "YES\n";
        cout << ans.size() << '\n';
        for (auto [a, b, c, d] : ans) {
            cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << ' ' << d + 1 << '\n';
        }
    }
    return 0;
}