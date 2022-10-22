// time-limit: 1000
// problem-url: https://codeforces.com/contest/1621/problem/C

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
#define MAXN 10005

int t;
int n;
int p[MAXN];

inline int qry(int i) {
    printf("? %d\n", i);
    fflush(stdout);
    int x; scanf("%d", &x);
    return x;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        REP (i, 0, n + 1) {
            p[i] = -1;
        }
        REP (i, 1, n + 1) {
            if (p[i] != -1) continue;
            int src = qry(i);
            int u = src;
            int v = qry(i);
            while (v != src) {
                p[u] = v;
                u = v;
                v = qry(i);
            }
            p[u] = v;
        }
        printf("!");
        REP (i, 1, n + 1) {
            printf(" %d", p[i]);
        }
        printf("\n");
        fflush(stdout);
    }
    return 0;
}