// time-limit: 2000
// problem-url: https://codeforces.com/contest/1625/problem/D

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
#define MAXL 30

int n, k;
int a[MAXN];
int ksb;

bool ans[MAXN];
vii vec;
map<int, int> mp;
void solve(vii a) {
    if (a.empty()) {
        return;
    }
    if (a.size() == 1) {
        debug(" %d\n", a[0].SE);
        ans[a[0].SE] = 1;
        return;
    }
    vii bit[MAXL + 5];
    REP (i, 0, MAXL + 5) {
        bit[i].clear();
    }
    vec.clear();
    for (auto [v, i] : a) {
        if (v != 0) {
            debug("?%d\n", i);
            int msb = 31 - __builtin_clz(v);
            bit[msb].pb(MP(v ^ (1 << msb), i));
        } else {
            vec.pb(MP(0, i));
        }
    }
    RREP (i, ksb, 0) {
        for (auto [v, j] : bit[i]) {
            debug("+%d\n", j);
            vec.pb(MP(v ^ (1 << i), j));
        }
    }
    int msk = 0;
    int mx = 0;
    int x = -1, y = -1;
    RREP (i, MAXL, 0) {
        msk |= 1 << i;
        mp.clear();
        for (auto [v, j] : vec) {
            mp[v & msk] = j;
        }
        mx |= 1 << i;
        bool found = 0;
        for (auto [v, j] : vec) {
            int t = (v & msk) ^ mx;
            if (mp.find(t) != mp.end()) {
                x = j, y = mp[t];
                found = 1;
                break;
            }
        }
        if (!found) {
            mx ^= 1 << i;
        }
    }
    debug("%d %d %d %d\n", ::a[x], ::a[y], x, y);
    if (x != -1 && (::a[x] ^ ::a[y]) >= k) {
        ans[x] = 1;
        ans[y] = 1;
    } else if (!vec.empty()) {
        ans[vec[0].SE] = 1;
    }
    RREP (i, MAXL, ksb + 1) {
        if (bit[i].empty()) continue;
        debug("%d\n", i);
        solve(bit[i]);
    }
}

int main() {
    scanf("%d%d", &n, &k);
    vii v;
    REP (i, 0, n) {
        scanf("%d", &a[i]);
        v.pb(MP(a[i], i));
    }
    if (k == 0) {
        printf("%d\n", n);
        REP (i, 0, n) {
            printf("%d ", i + 1);
        }
        printf("\n");
        return 0;
    }
    ksb = 31 - __builtin_clz(k);
    solve(v);
    int cnt = 0;
    REP (i, 0, n) {
        if (ans[i]) cnt++;
    }
    if (cnt <= 1) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", cnt);
    REP (i, 0, n) {
        if (ans[i]) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
    return 0;
}