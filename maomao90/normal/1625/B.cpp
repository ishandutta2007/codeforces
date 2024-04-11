// time-limit: 2000
// problem-url: https://codeforces.com/contest/1625/problem/B

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
#define MAXN 200005

int t;
int n;
int a[MAXN];
vi v[MAXN];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        REP (i, 0, n) {
            scanf("%d", &a[i]);
            v[a[i]].pb(i);
        }
        int ans = -1;
        REP (i, 0, n) {
            if (v[a[i]].empty()) continue;
            REP (j, 0, v[a[i]].size() - 1) {
                mxto(ans, n - v[a[i]][j + 1] + v[a[i]][j]);
            }
            v[a[i]].clear();
        }
        printf("%d\n", ans);
    }
    return 0;
}