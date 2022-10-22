// time-limit: 2000
// problem-url: https://codeforces.com/contest/1677/problem/C

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

const int INF = 1000000005;
const ll LINF = 1000000000000000005ll;
const int MAXN = 200005;

int t;
int n;
int a[MAXN], b[MAXN], mpb[MAXN];
bool vis[MAXN];

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        REP (i, 0, n) {
            cin >> a[i];
        }
        REP (i, 0, n) {
            cin >> b[i];
        }
        REP (i, 0, n) {
            mpb[b[i]] = i;
        }
        REP (i, 0, n) {
            vis[i] = 0;
        }
        int take = 0;
        REP (i, 0, n) {
            if (vis[i]) continue;
            vis[i] = 1;
            int l = 1, u = i;
            while (mpb[a[u]] != i) {
                l++;
                u = mpb[a[u]];
                vis[u] = 1;
            }
            take += l / 2;
        }
        ll ans = 0;
        REP (i, 1, take + 1) {
            ans += n - i + 1 - i;
        }
        cout << ans * 2 << '\n';
    }
    return 0;
}