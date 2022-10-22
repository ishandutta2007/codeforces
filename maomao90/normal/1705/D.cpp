// time-limit: 1500
// problem-url: https://codeforces.com/contest/1705/problem/D

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

int q;
int n;
string s, t;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> q;
    while (q--) {
        cin >> n;
        cin >> s >> t;
        if (s[0] != t[0] || s[n - 1] != t[n - 1]) {
            cout << -1 << '\n';
            continue;
        }
        vi vs;
        REP (i, 0, n - 1) {
            if (s[i] != s[i + 1]) {
                vs.pb(i);
            }
        }
        vi vt;
        REP (i, 0, n - 1) {
            if (t[i] != t[i + 1]) {
                vt.pb(i);
            }
        }
        if (SZ(vs) != SZ(vt)) {
            cout << -1 << '\n';
            continue;
        }
        ll ans = 0;
        REP (i, 0, SZ(vs)) {
            ans += abs(vs[i] - vt[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}