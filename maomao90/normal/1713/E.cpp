// time-limit: 1000
// problem-url: https://codeforces.com/problemset/problem/1713/E

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
const int MAXN = 1005;

int t;
int n;
int a[MAXN][MAXN];

int p[MAXN], rnk[MAXN];
bool pw[MAXN], s[MAXN];
int findp(int i) {
    if (p[i] == i) return i;
    int tp = p[i];
    p[i] = findp(p[i]);
    s[i] = pw[i] ^ s[tp];
    pw[i] = s[p[i]] ^ s[i];
    cerr << i << " -> " << p[i] << ' ' << s[i] << ' ' << pw[i] << '\n';
    return p[i];
}
bool join(int a, int b, int w) {
    int pa = findp(a), pb = findp(b);
    if (pa == pb) {
        return 0;
    }
    w ^= pw[a] ^ pw[b];
    if (rnk[pa] < rnk[pb]) swap(pa, pb);
    if (rnk[pa] == rnk[pb]) rnk[pa]++;
    p[pb] = pa;
    pw[pb] = w;
    return 1;
}
inline bool gets(int a) {
    findp(a);
    return s[a];
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        REP (i, 0, n) {
            REP (j, 0, n) {
                cin >> a[i][j];
            }
        }
        REP (i, 0, n) {
            p[i] = i;
            rnk[i] = 0;
            s[i] = 0;
            pw[i] = 0;
        }
        REP (i, 0, n) {
            REP (j, i + 1, n) {
                bool w;
                if (a[i][j] < a[j][i]) {
                    w = 0;
                } else if (a[i][j] > a[j][i]) {
                    w = 1;
                } else {
                    continue;
                }
                cerr << i << ' ' << j << ' ' << w << '\n';
                bool z = join(i, j, w);
                bool si = gets(i), sj = gets(j);
                cerr << ' ' << z << ' ' << si << ' ' << sj << '\n';
                if (si ^ sj) {
                    swap(a[i][j], a[j][i]);
                }
            }
        }
        REP (i, 0, n) {
            REP (j, 0, n) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}