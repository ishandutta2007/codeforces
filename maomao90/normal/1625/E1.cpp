// time-limit: 6000
// problem-url: https://codeforces.com/contest/1625/problem/E1

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
#define MAXN 300005
#define MAXL 20

int n, q;
char s[MAXN];
stack<int> brk, comp;
int p[MAXL][MAXN];
ll cost[MAXL][MAXN];

int main() {
    scanf("%d%d", &n, &q);
    scanf(" %s", s);
    memset(p, -1, sizeof p);
    REP (i, 0, n) {
        if (s[i] == '(') {
            brk.push(i);
        } else {
            if (brk.empty()) continue;
            int j = brk.top(); brk.pop();
            int sze = 0;
            while (!comp.empty() && comp.top() > j) {
                int k = comp.top(); comp.pop();
                cost[0][j] += cost[0][k];
                sze++;
            }
            cost[0][j] += (ll) sze * (sze - 1) / 2 + 1;
            debug("%d: %lld\n", j, cost[0][j]);
            comp.push(j);
            p[0][j] = i + 1;
        }
    }
    REP (k, 1, MAXL) {
        REP (i, 0, n) {
            if (p[k - 1][i] == -1) {
                p[k][i] = -1;
                cost[k][i] = cost[k - 1][i];
            } else {
                p[k][i] = p[k - 1][p[k - 1][i]];
                cost[k][i] = cost[k - 1][i] + cost[k - 1][p[k - 1][i]];
            }
        }
    }
    while (q--) {
        int t, l, r; scanf("%d%d%d", &t, &l, &r);
        l--; r--;
        if (t == 1) {
        } else {
            int u = l;
            int cnt = 0;
            ll res = 0;
            RREP (k, MAXL - 1, 0) {
                if (p[k][u] == -1 || p[k][u] - 1 > r) continue;
                res += cost[k][u];
                u = p[k][u];
                cnt += 1 << k;
            }
            res += (ll) cnt * (cnt - 1) / 2;
            printf("%lld\n", res);
        }
    }
    return 0;
}