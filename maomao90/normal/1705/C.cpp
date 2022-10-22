// time-limit: 2000
// problem-url: https://codeforces.com/contest/1705/problem/C

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
int n, c, q;
string s;
ll l[MAXN], r[MAXN];
ll plen[MAXN];

int find(ll x) {
    if (x < n) {
        return x;
    }
    int id = upper_bound(plen, plen + c + 1, x) - plen;
    cerr << x << ": " << id << '\n';
    return find(l[id] + x - (id == 0 ? 0 : plen[id - 1]));
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n >> c >> q;
        cin >> s;
        plen[0] = n;
        REP (i, 1, c + 1) {
            cin >> l[i] >> r[i];
            l[i]--; r[i]--;
            plen[i] = r[i] - l[i] + 1;
            plen[i] += plen[i - 1];
            cerr << i << ' ' << plen[i] << '\n';
        }
        REP (i, 0, q) {
            ll k; cin >> k;
            k--;
            cout << s[find(k)] << '\n';
        }
    }
    return 0;
}