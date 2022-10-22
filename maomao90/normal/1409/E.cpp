// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/1409/E

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

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vi pts(n, 0);
        REP (i, 0, n) {
            cin >> pts[i];
        }
        REP (i, 0, n) {
            int y; cin >> y;
        }
        sort(ALL(pts));
        int s = 0;
        vi pmx(n, 0);
        REP (i, 0, n) {
            while (pts[i] - pts[s] > k) {
                s++;
            }
            pmx[i] = i - s + 1;
            if (i) {
                mxto(pmx[i], pmx[i - 1]);
            }
        }
        vi smx(n + 1, 0);
        int e = n - 1;
        RREP (i, n - 1, 0) {
            while (pts[e] - pts[i] > k) {
                e--;
            }
            cerr << i << ' ' << e << '\n';
            smx[i] = e - i + 1;
            mxto(smx[i], smx[i + 1]);
        }
        int ans = 0;
        REP (i, 0, n) {
            mxto(ans, pmx[i] + smx[i + 1]);
        }
        cout << ans << '\n';
    }
    return 0;
}