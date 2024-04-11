// time-limit: 1000
// problem-url: https://codeforces.com/contest/1166/problem/D

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
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
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
ll a, b, m;
ll ans[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> a >> b >> m;
        if (a == b) {
            cout << 1 << ' ' << a << '\n';
            continue;
        }
        ll lo = a, hi = a;
        int len = -1;
        ll rem = b;
        REP (k, 1, 51) {
            lo = a * (1ll << max(0, k - 2));
            hi = lo;
            if (k >= 2) {
                lo += (1ll << max(0, k - 2));
                hi += m * (1ll << max(0, k - 2));
            }
            cerr << lo << ' ' << hi << '\n';
            if (lo > b) {
                break;
            }
            if (lo <= b && b <= hi) {
                len = k;
                rem -= lo;
                break;
            }
        }
        if (len == -1) {
            cout << -1 << '\n';
            continue;
        }
        REP (k, 1, len) {
            ll f = 1ll << max(0, len - k - 2);
            ll p = min(m - 1, rem / f);
            cerr << k << ' ' << f << ' ' << p << '\n';
            rem -= p * f;
            cerr << ' ' << p * f << '\n';
            ans[k] = p + 1;
        }
        cerr << rem << '\n';
        ans[0] = a;
        ll sm = a;
        REP (k, 1, len) {
            ans[k] += sm;
            sm += ans[k];
        }
        //assert(ans[len - 1] == b);
        cout << len;
        REP (k, 0, len) {
            cout << ' ' << ans[k];
        }
        cout << '\n';
    }
    return 0;
}