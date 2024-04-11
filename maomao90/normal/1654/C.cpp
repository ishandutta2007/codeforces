// time-limit: 2000
// problem-url: https://codeforces.com/contest/1654/problem/C

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
int n;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        map<int, int> mp;
        ll sm = 0;
        REP (i, 0, n) {
            int a; cin >> a;
            mp[a]++;
            sm += a;
        }
        if (n == 1) {
            cout << "YES\n";
            continue;
        }
        cerr << n << '\n';
        ll x = sm, xc = 1, y = sm, yc = 0;
        int ans = 0;
        while (x) {
            ll nx = x / 2, ny = x / 2 + 1;
            ll nxc = 0, nyc = 0;
            if (x / 2 == nx) {
                nxc += xc;
            } else {
                assert(0);
            }
            if ((x + 1) / 2 == nx) {
                nxc += xc;
            } else {
                nyc += xc;
            }
            if (y / 2 == nx) {
                nxc += yc;
            } else {
                nyc += yc;
            }
            if ((y + 1) / 2 == nx) {
                nxc += yc;
            } else {
                nyc += yc;
            }
            x = nx;
            xc = nxc;
            y = ny;
            yc = nyc;
            cerr << x << ' ' << xc << ' ' << y << ' ' << yc << '\n';
            cerr << mp[x] << ' ' << mp[y] << '\n';
            int mn = min(mp[x], (int) xc);
            ans += mn;
            xc -= mn;
            mp[x] -= mn;
            mn = min(mp[y], (int) yc);
            ans += mn;
            yc -= mn;
            mp[y] -= mn;
            cerr << x << ' ' << xc << ' ' << y << ' ' << yc << '\n';
        }
        cerr << ans << '\n';
        if (ans == n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}