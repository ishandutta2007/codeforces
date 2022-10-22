// time-limit: 2000
// problem-url: https://codeforces.com/contest/1648/problem/B

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
#define MAXN 1000005

int t;
int n, c;
int a[MAXN];
int psm[MAXN], occ[MAXN];

ll choose(ll n, ll r) {
    ll res = 1;
    RREP (i, n, n - r + 1) {
        res *= i;
    }
    REP (i, 1, r + 1) {
        res /= i;
    }
    return res;
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n >> c;
        REP (i, 0, c + 1) {
            psm[i] = 0;
            occ[i] = 0;
        }
        REP (i, 0, n) {
            cin >> a[i];
            psm[a[i]]++;
            occ[a[i]]++;
        }
        REP (i, 1, c + 1) {
            psm[i] += psm[i - 1];
        }
        ll ans = 0;
        REP (i, 1, c + 1) {
            if (occ[i] == 0) continue;
            REP (j, 1, c + 1) {
                ll mnc = (ll) i * j, mxc = min((ll) c, (ll) (i + 1) * j - 1);
                if (mnc > c) break;
                if (occ[j] == 0) continue;
                ans += (ll) psm[mxc] - psm[mnc - 1];
            }
        }
        cerr << ans << '\n';
        ll cur = 0;
        REP (i, 1, c + 1) {
            if (occ[i] > 0) {
                cur++;
            }
            ans -= (ll) cur * occ[i];
        }
        if (ans == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}