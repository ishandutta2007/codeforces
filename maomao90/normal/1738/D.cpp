// time-limit: 2000
// problem-url: https://codeforces.com/contest/1738/problem/D

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
int b[MAXN];
int a[MAXN];
bool c[MAXN];
vi p[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        REP (i, 0, n + 2) {
            p[i].clear();
        }
        REP (i, 1, n + 1) {
            cin >> b[i];
            p[b[i]].pb(i);
        }
        assert(p[0].empty() || p[n + 1].empty());
        int z = 0;
        int m = 0, pm = 0;
        int k = 0;
        if (!p[0].empty()) {
            z = 1;
            for (int i : p[0]) {
                a[m++] = i;
            }
        } else {
            z = 0;
            for (int i : p[n + 1]) {
                a[m++] = i;
                k++;
            }
        }
        while (m < n) {
            bool found = 0;
            cerr << pm << ' ' << m << '\n';
            REP (i, pm, m) {
                if (!p[a[i]].empty()) {
                    assert(!found);
                    found = 1;
                }
            }
            assert(found);
            REP (i, pm, m) {
                if (!p[a[i]].empty()) {
                    swap(a[i], a[m - 1]);
                }
            }
            pm = m;
            z ^= 1;
            for (int i : p[a[pm - 1]]) {
                a[m++] = i;
                if (z == 0) {
                    k++;
                }
            }
        }
        cout << k << '\n';
        REP (i, 0, n) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}