// time-limit: 3000
// problem-url: https://codeforces.com/contest/1666/problem/E

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

int n, m;
int a[MAXN];
int dpsm[MAXN][2];

int main() {
    cin >> m >> n;
    REP (i, 1, n + 1) {
        cin >> a[i];
    }
    a[n + 1] = m;
    int lo = 1, hi = m, mid;
    while (lo < hi) {
        mid = lo + hi + 1 >> 1;
        bool pos = 1;
        int p = 0;
        REP (i, 1, n + 1) {
            if (p + mid > a[i + 1]) {
                pos = 0;
                break;
            }
            p = max(a[i], p + mid);
        }
        if (pos) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    int x = lo;
    lo = 1, hi = m, mid;
    while (lo < hi) {
        mid = lo + hi >> 1;
        bool pos = 1;
        int p = 0;
        REP (i, 1, n + 1) {
            if (p + mid < a[i]) {
                pos = 0;
                break;
            }
            if (i == n && p + mid < m) {
                pos = 0;
                break;
            }
            p = min(a[i + 1], p + mid);
        }
        if (pos) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    int y = hi;
    cerr << x << ' ' << y << '\n';
    REP (i, 1, n + 1) {
        dpsm[i][0] = max(i == n ? m : a[i], dpsm[i - 1][0] + x);
        dpsm[i][1] = min(a[i + 1], dpsm[i - 1][1] + y);
        cerr << i << ' ' << dpsm[i][0] << ' ' << dpsm[i][1] << '\n';
    }
    int lst = m;
    vi vec;
    RREP (i, n - 1, 1) {
        bool done = 0;
        REP (j, dpsm[i][0], min(dpsm[i][1], lst) + 1) {
            if (lst - j >= x && lst - j <= y) {
                vec.pb(j);
                lst = j;
                done = 1;
                break;
            }
        }
        assert(done);
    }
    reverse(ALL(vec));
    cout << 0 << ' ';
    for (int i : vec) {
        cout << i << '\n';
        cout << i << ' ';
    }
    cout << m << '\n';
}