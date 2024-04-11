// time-limit: 1000
// problem-url: https://codeforces.com/contest/1736/problem/D

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
string s;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        int o = 0;
        REP (i, 0, 2 * n) {
            o += s[i] == '1';
        }
        if (o % 2 == 1) {
            cout << -1 << '\n';
            continue;
        }
        vi v;
        for (int i = 0; i < 2 * n; i += 2) {
            if (s[i] != s[i + 1]) {
                v.pb(i + (s[i] == '1'));
            }
        }
        cout << SZ(v);
        assert(SZ(v) % 2 == 0);
        REP (i, 0, SZ(v)) {
            cout << ' ' << (v[i] ^ (i & 1)) + 1;
        }
        cout << '\n';
        for (int i = 1; i <= 2 * n; i += 2) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}