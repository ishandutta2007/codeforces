// time-limit: 2000
// problem-url: https://codeforces.com/contest/1671/problem/D

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
int n, x;
int a[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n >> x;
        int mn = INF, mx = -1;
        ll ans = 0;
        REP (i, 0, n) {
            cin >> a[i];
            mnto(mn, a[i]);
            mxto(mx, a[i]);
            if (i > 0) {
                ans += abs(a[i] - a[i - 1]);
            }
        }
        if (mn != 1) {
            int ex = min(a[0] - 1, a[n - 1] - 1);
            REP (i, 1, n) {
                mnto(ex, a[i] - 1 + a[i - 1] - 1 - abs(a[i] - a[i - 1]));
            }
            ans += ex;
        }
        if (mx < x) {
            int ex = min(x - a[0], x - a[n - 1]);
            REP (i, 1, n) {
                mnto(ex, x - a[i] + x - a[i - 1] - abs(a[i] - a[i - 1]));
            }
            ans += ex;
        }
        cout << ans << '\n';
    }
    return 0;
}