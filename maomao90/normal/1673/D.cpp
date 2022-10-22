// time-limit: 1000
// problem-url: https://codeforces.com/contest/1673/problem/D

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
#define MAXN 200005
#define MOD 1000000007

int t;
ll s[2], e[2], r[2], n[2];
ll ans;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        REP (i, 0, 2) {
            cin >> s[i] >> r[i] >> n[i];
            e[i] = s[i] + (n[i] - 1) * r[i];
            cerr << s[i] << ' ' << e[i] << ' ' << r[i] << ' ' << n[i] << '\n';
        }
        if (r[0] > r[1] || r[1] % r[0] != 0 || s[1] < s[0] || e[1] > e[0] ||
                (s[0] % r[0] + r[0]) % r[0] != (s[1] % r[0] + r[0]) % r[0]) {
            cout << 0 << '\n';
            continue;
        }
        if (s[1] - r[1] < s[0] || e[1] + r[1] > e[0]) {
            cout << -1 << '\n';
            continue;
        }
        // lcm(r[0], nr) = r[1]
        ans = 0;
        for (ll nr = 1; nr * nr <= r[1]; nr++) {
            REP (z, 0, 2) {
                if (z == 1 && nr * nr == r[1]) {
                    break;
                }
                ll g = __gcd(r[0], nr);
                ll lcm = r[0] / g * nr;
                if (lcm == r[1]) {
                    ll cnt = r[1] / nr;
                    ans += cnt * cnt % MOD;
                    if (ans >= MOD) {
                        ans -= MOD;
                    }
                }
                nr = r[1] / nr;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}