// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/1406/D

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

int n;
int a[MAXN];
int q;
ll d[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n;
    REP (i, 1, n + 1) {
        cin >> a[i];
    }
    ll sm = 0;
    REP (i, 1, n + 1) {
        d[i] = a[i] - a[i - 1];
        if (i > 1) {
            sm += max(0ll, d[i]);
        }
    }
    auto solve = [&] () {
        ll y = (d[1] + sm) / 2;
        if (d[1] + sm >= 0 && (d[1] + sm) % 2 == 1) {
            y++;
        }
        return y;
    };
    cout << solve() << '\n';
    cin >> q;
    while (q--) {
        int l, r, x; cin >> l >> r >> x;
        if (l > 1) {
            sm -= max(0ll, d[l]);
        }
        d[l] += x;
        if (l > 1) {
            sm += max(0ll, d[l]);
        }
        if (r < n) {
            sm -= max(0ll, d[r + 1]);
            d[r + 1] -= x;
            sm += max(0ll, d[r + 1]);
        }
        cout << solve() << '\n';
    }
    return 0;
}