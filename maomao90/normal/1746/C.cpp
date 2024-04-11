// time-limit: 2000
// problem-url: https://codeforces.com/contest/1746/problem/C

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

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        REP (i, 0, n) {
            cin >> a[i];
        }
        vii v;
        REP (i, 0, n - 1) {
            v.pb({a[i] - a[i + 1], i});
        }
        sort(ALL(v), greater<ii>());
        vi ans;
        REP (i, 0, SZ(v)) {
            assert(n - i >= v[i].FI);
            ans.pb(v[i].SE + 1);
        }
        while (SZ(ans) < n) {
            ans.pb(0);
        }
        reverse(ALL(ans));
        for (int i : ans) {
            cout << i + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}