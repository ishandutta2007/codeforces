// time-limit: 2000
// problem-url: https://codeforces.com/contest/1700/problem/D

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

int n;
int v[MAXN];
int q;
int t[MAXN];
ll pv[MAXN];
ll mn[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n;
    REP (i, 0, n) {
        cin >> v[i];
    }
    REP (i, 0, n) {
        pv[i] = v[i];
        if (i) {
            pv[i] += pv[i - 1];
        }
    }
    cin >> q;
    REP (i, 0, q) {
        cin >> t[i];
    }
    ll cur = 0;
    REP (i, 0, n) {
        mxto(cur, (pv[i] - 1) / (i + 1) + 1);
    }
    mn[n - 1] = cur;
    RREP (i, n - 2, 0) {
        mxto(cur, (pv[n - 1] - 1) / (i + 1) + 1);
        mn[i] = cur;
    }
    REP (i, 0, n) {
        cerr << i << ": " << mn[i] << '\n';
    }
    REP (i, 0, q) {
        int p = lower_bound(mn, mn + n, t[i], greater<int>()) - mn;
        if (p == n) {
            cout << -1 << '\n';
        } else {
            cout << p + 1 << '\n';
        }
    }
    return 0;
}