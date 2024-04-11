// time-limit: 2000
// problem-url: https://codeforces.com/contest/1338/problem/C

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
#define MAXL 31

int t;
ll n;
ll pw[MAXL];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0); cin.tie(0);
#endif
    cin >> t;
    pw[0] = 1;
    REP (i, 1, MAXL) {
        pw[i] = pw[i - 1] * 4;
    }
    while (t--) {
        cin >> n;
        ll a = 1;
        REP (i, 0, MAXL) {
            if (pw[i] * 3 < n) {
                n -= pw[i] * 3;
                a <<= 2;
            } else {
                break;
            }
        }
        a += (n - 1) / 3;
        auto get = [&] (ll x, ll k) {
            return x >> k & 1;
        };
        ll b = 0;
        REP (i, 0, 62) {
            if (i % 2 == 0) {
                b |= ((ll) get(a, i + 1)) << i;
            } else {
                b |= ((ll) get(a, i) ^ get(a, i - 1)) << i;
            }
        }
        if (n % 3 == 1) {
            cout << a << '\n';
        } else if (n % 3 == 2) {
            cout << b << '\n';
        } else {
            cout << (a ^ b) << '\n';
        }
    }
    return 0;
}