// time-limit: 2000
// problem-url: https://codeforces.com/contest/1621/problem/E

// But let justice roll on like a river,
// righteousness like a never-failing stream!
// Amos 5:24
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

#ifdef DEBUG
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MAXN 100005

int t;
int n, m;
int a[MAXN];
int k[MAXN];
vi b[MAXN];
ll sm[MAXN];

#define MLR int mid = lo + hi >> 1; int lc = u << 1, rc = u << 1 ^ 1
int mn[MAXN * 4], lz[MAXN * 4];
void propo(int u, int lo, int hi) {
    if (lo == hi | lz[u] == 0) return;
    MLR;
    mn[lc] += lz[u];
    mn[rc] += lz[u];
    lz[lc] += lz[u];
    lz[rc] += lz[u];
    lz[u] = 0;
}
void incre(int p, int x, int u = 1, int lo = 0, int hi = MAXN) {
    if (p >= hi) {
        lz[u] += x;
        mn[u] += x;
        return;
    }
    propo(u, lo, hi);
    MLR;
    incre(p, x, lc, lo, mid);
    if (p > mid) {
        incre(p, x, rc, mid + 1, hi);
    }
    mn[u] = min(mn[lc], mn[rc]);
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        REP (i, 0, n) {
            scanf("%d", &a[i]);
            incre(a[i], 1);
        }
        REP (i, 0, m) {
            scanf("%d", &k[i]);
            b[i].clear();
            b[i].resize(k[i]);
            sm[i] = 0;
            REP (j, 0, k[i]) {
                scanf("%d", &b[i][j]);
                sm[i] += b[i][j];
            }
            incre((sm[i] - 1) / k[i] + 1, -1);
        }
        string ans = "";
        REP (i, 0, m) {
            debug("%d %d\n", i, (sm[i] - 1) / k[i] + 1);
            incre((sm[i] - 1) / k[i] + 1, 1);
            REP (j, 0, k[i]) {
                debug(" %d %d\n", j, (sm[i] - b[i][j] - 1) / (k[i] - 1) + 1);
                incre((sm[i] - b[i][j] - 1) / (k[i] - 1) + 1, -1);
                if (mn[1] >= 0) {
                    ans += '1';
                } else {
                    ans += '0';
                }
                incre((sm[i] - b[i][j] - 1) / (k[i] - 1) + 1, 1);
            }
            incre((sm[i] - 1) / k[i] + 1, -1);
        }
        printf("%s\n", ans.c_str());
        REP (i, 0, m) {
            incre((sm[i] - 1) / k[i] + 1, 1);
        }
        REP (i, 0, n) {
            incre(a[i], -1);
        }
    }
    return 0;
}