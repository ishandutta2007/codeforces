// time-limit: 1000
// problem-url: https://codeforces.com/contest/1684/problem/C

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
const int MAXN = 200005;

int t;
int n, m;
vector<vi> a, b;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n >> m;
        a = vector<vi>(n, vi(m, 0));
        REP (i, 0, n) {
            REP (j, 0, m) {
                cin >> a[i][j];
            }
        }
        b = a;
        REP (i, 0, n) {
            sort(ALL(b[i]));
        }
        int fi = -1, se = -1;
        bool pos = 1;
        REP (i, 0, n) {
            int cfi = -1, cse = -1;
            REP (j, 0, m) {
                if (a[i][j] != b[i][j]) {
                    //cout << ' ' << i << ' ' << j << '\n';
                    if (cfi == -1) {
                        cfi = j;
                    } else if (cse == -1) {
                        cse = j;
                    } else {
                        pos = 0;
                        break;
                    }
                }
            }
            if (!pos) break;
            if (cfi == -1) {
                continue;
            }
            if (cse == -1) {
                pos = 0;
                break;
            }
            if (fi == -1) {
                fi = cfi;
                se = cse;
            } else if (fi != cfi || se != cse) {
                pos = 0;
                break;
            }
        }
        if (!pos) {
            cout << -1 << '\n';
            continue;
        }
        if (fi == -1) {
            fi = 0;
            se = 0;
        }
        REP (i, 0, n) {
            if (a[i][se] == b[i][fi] && a[i][fi] == b[i][se]) {
            } else {
                pos = 0;
                break;
            }
        }
        if (!pos) {
            cout << -1 << '\n';
            continue;
        }
        cout << fi + 1 << ' ' << se + 1 << '\n';
    }
    return 0;
}