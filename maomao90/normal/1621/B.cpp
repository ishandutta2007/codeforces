// time-limit: 2000
// problem-url: https://codeforces.com/contest/1621/problem/B

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
int n;
int l[MAXN], r[MAXN], c[MAXN];
map<int, int> mp;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        REP (i, 0, n) {
            scanf("%d%d%d", &l[i], &r[i], &c[i]);
        }
        mp.clear();
        int lo = INF, hi = -INF, ans = INF;
        REP (i, 0, n) {
            bool dt = 0;
            dt |= mnto(lo, l[i]); dt |= mxto(hi, r[i]);
            if (mp.find(l[i]) == mp.end()) {
                mp[l[i]] = c[i];
            } else {
                mnto(mp[l[i]], c[i]);
            }
            if (mp.find(r[i]) == mp.end()) {
                mp[r[i]] = c[i];
            } else {
                mnto(mp[r[i]], c[i]);
            }
            if (dt) {
                ans = mp[lo] + mp[hi];
            } else {
                mnto(ans, mp[lo] + mp[hi]);
            }
            if (l[i] == lo && r[i] == hi) {
                mnto(ans, c[i]);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}