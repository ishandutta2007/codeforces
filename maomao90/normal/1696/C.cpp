// time-limit: 2000
// problem-url: https://codeforces.com/contest/1696/problem/C

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
int n, m;
vector<pll> a;
int k;
int b[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n >> m;
        a.clear();
        REP (i, 0, n) {
            int ta; cin >> ta;
            ll cnt = 1;
            while (ta % m == 0) {
                ta /= m;
                cnt *= m;
            }
            a.pb({ta, cnt});
        }
        cin >> k;
        REP (i, 0, k) {
            cin >> b[i];
        }
        vector<pll> ta;
        int p = -1;
        ll sm = 0;
        for (auto [x, c] : a) {
            if (p == -1) {
                p = x;
            } else if (p != x) {
                ta.pb({p, sm});
                p = x;
                sm = 0;
            }
            sm += c;
        }
        ta.pb({p, sm});
        a = ta;
        int ptr = 0;
        REP (i, 0, k) {
            if (ptr >= SZ(a)) {
                ptr = -1;
                break;
            }
            if (b[i] % a[ptr].FI != 0) {
                ptr = -1;
                break;
            }
            ll tmp = a[ptr].FI;
            ll cnt = 1;
            while (tmp < b[i]) {
                tmp *= m;
                cnt *= m;
            }
            if (tmp != b[i]) {
                ptr = -1;
                break;
            }
            a[ptr].SE -= cnt;
            if (a[ptr].SE < 0) {
                ptr = -1;
                break;
            }
            if (a[ptr].SE == 0) {
                ptr++;
            }
        }
        if (ptr != SZ(a)) {
            ptr = -1;
        }
        if (ptr == -1) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
    return 0;
}