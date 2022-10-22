// time-limit: 2000
// problem-url: https://codeforces.com/contest/1738/problem/A

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
int a[MAXN];
int b[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        int cnt = 0;
        REP (i, 0, n) {
            cin >> a[i];
            cnt += a[i];
        }
        mnto(cnt, n - cnt);
        ll ans = 0;
        REP (i, 0, n) {
            cin >> b[i];
            ans += b[i];
        }
        vi v;
        REP (i, 0, n) {
            if (a[i] == 0) {
                v.pb(b[i]);
            }
        }
        sort(ALL(v), greater<int>());
        REP (i, 0, cnt) {
            ans += v[i];
        }
        int mn;
        if (!v.empty()) {
            mn = v.back();
        }
        v.clear();
        REP (i, 0, n) {
            if (a[i] == 1) {
                v.pb(b[i]);
            }
        }
        sort(ALL(v), greater<int>());
        REP (i, 0, cnt) {
            ans += v[i];
        }
        if (!v.empty()) {
            mnto(mn, v.back());
        }
        if (2 * cnt == n) {
            ans -= mn;
        }
        cout << ans << '\n';
    }
    return 0;
}