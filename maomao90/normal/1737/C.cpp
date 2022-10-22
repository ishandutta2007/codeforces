// time-limit: 1000
// problem-url: https://codeforces.com/contest/1737/problem/C

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
const int MAXN = 200005;

int t;
int n;
int r[3], c[3];
int x, y;
int rc[MAXN], cc[MAXN];

bool has(int x, int y) {
    REP (i, 0, 3) {
        rc[r[i]]++;
        cc[c[i]]++;
    }
    int ri = 0, ci = 0;
    REP (i, 0, 3) {
        if (!ri && rc[r[i]] == 2) {
            ri = r[i];
        }
        if (!ci && cc[c[i]] == 2) {
            ci = c[i];
        }
    }
    REP (i, 0, 3) {
        rc[r[i]]--;
        cc[c[i]]--;
    }
    return ri == x && ci == y;
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        REP (i, 0, 3) {
            cin >> r[i] >> c[i];
        }
        cin >> x >> y;
        if (has(1, 1)) {
            if (x == 1 || y == 1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }
        if (has(1, n)) {
            if (x == 1 || y == n) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }
        if (has(n, 1)) {
            if (x == n || y == 1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }
        if (has(n, n)) {
            if (x == n || y == n) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }
        REP (i, 0, 3) {
            rc[r[i]]++;
            cc[c[i]]++;
        }
        int ri = 0, ci = 0;
        REP (i, 0, 3) {
            if (!ri && rc[r[i]] == 2) {
                ri = r[i];
            }
            if (!ci && cc[c[i]] == 2) {
                ci = c[i];
            }
        }
        if (ri % 2 == x % 2 || ci % 2 == y % 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        REP (i, 0, 3) {
            rc[r[i]]--;
            cc[c[i]]--;
        }
    }
    return 0;
}