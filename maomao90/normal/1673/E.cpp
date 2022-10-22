// time-limit: 2000
// problem-url: https://codeforces.com/contest/1673/problem/E

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
#define MAXN 2000005

const int MOD = 1 << 20;

int n, k;
int b[MAXN];
bool ans[MAXN];

ll fpow(ll b, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            res = res * b;
        }
        b = b * b;
        p >>= 1;
    }
    return res;
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n >> k;
    REP (i, 0, n) {
        cin >> b[i];
    }
    if (n == 1) {
        cout << 1;
        REP (i, 0, b[0]) {
            cout << 0;
        }
        cout << '\n';
        return 0;
    }
    REP (i, 0, n) {
        bool end = i == 0;
        ll x = b[i];
        cerr << i << '\n';
        REP (j, i, n) {
            cerr << ' ' << j << '\n';
            if (j != i) {
                if (b[j] > 20) {
                    break;
                }
                x *= fpow(2, b[j]);
                if (x >= MOD) {
                    break;
                }
            }
            int w = j - i + 1;
            int end = (i == 0) + (j + 1 == n);
            int tp = n - w - 2 + end,
                bt = k - 2 + end;
            mxto(bt, 0);
            cerr << "  " << tp << ' ' << bt << '\n';
            if (tp >= bt && (tp == 0 || (bt > 0 && (((tp - 1) & (bt - 1)) == (bt - 1))))) {
                cerr << "   " << x << '\n';
                ans[x] ^= 1;
            }
        }
    }
    int j = -1;
    RREP (i, MOD - 1, 0) {
        if (ans[i] != 0) {
            j = i;
            break;
        }
    }
    if (j == -1) {
        cout << 0 << '\n';
    } else {
        RREP (i, j, 0) {
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}