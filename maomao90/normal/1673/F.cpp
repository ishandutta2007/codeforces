// time-limit: 2000
// problem-url: https://codeforces.com/contest/1673/problem/F

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
#define MAXN 35

int n, k;
int pot[MAXN][MAXN];
ii mp[MAXN * MAXN];

int main() {
    n = 32;
    int j = 1;
    RREP (k, 9, 0) {
        if (k % 2 == 1) {
            int x = 0;
            REP (i, 0, n) {
                if (i % (n / j) == n / j / 2) {
                    x ^= 1;
                }
                REP (j, 0, n) {
                    pot[i][j] |= x << k;
                }
            }
        } else {
            int x = 0;
            REP (i, 0, n) {
                if (i % (n / j) == n / j / 2) {
                    x ^= 1;
                }
                REP (j, 0, n) {
                    pot[j][i] |= x << k;
                }
            }
            j *= 2;
        }
    }
    REP (i, 0, n) {
        REP (j, 0, n) {
            mp[pot[i][j]] = {i, j};
        }
    }
    ll sm = 0;
    REP (i, 0, n) {
        REP (j, 0, n - 1) {
            int w = pot[i][j] ^ pot[i][j + 1];
            sm += w;
        }
    }
    REP (i, 0, n - 1) {
        REP (j, 0, n) {
            int w = pot[i][j] ^ pot[i + 1][j];
            sm += w;
        }
    }
    cerr << sm << '\n';
    cin >> n >> k;
    REP (i, 0, n) {
        REP (j, 0, n - 1) {
            int w = pot[i][j] ^ pot[i][j + 1];
            cout << w << ' ';
        }
        cout << endl;
    }
    REP (i, 0, n - 1) {
        REP (j, 0, n) {
            int w = pot[i][j] ^ pot[i + 1][j];
            cout << w << ' ';
        }
        cout << endl;
    }
    int px = 0;
    while (k--) {
        int x; cin >> x;
        px ^= x;
        auto [a, b] = mp[px];
        cout << a + 1 << ' ' << b + 1 << endl;
    }
    return 0;
}