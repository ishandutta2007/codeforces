// time-limit: 2000
// problem-url: https://codeforces.com/contest/1667/problem/A

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

int n;
int a[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n;
    REP (i, 0, n) {
        cin >> a[i];
    }
    ll ans = LINF;
    REP (i, 0, n) {
        ll p = 0;
        ll cur = 0;
        REP (j, i + 1, n) {
            ll x = p / a[j] + 1;
            cur += x;
            assert(x * a[j] > p);
            p = x * a[j];
        }
        p = 0;
        RREP (j, i - 1, 0) {
            ll x = p / a[j] + 1;
            cur += x;
            assert(x * a[j] > p);
            p = x * a[j];
        }
        mnto(ans, cur);
    }
    cout << ans << '\n';
    return 0;
}