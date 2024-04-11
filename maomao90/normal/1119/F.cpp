// time-limit: 3000
// problem-url: https://codeforces.com/contest/1119/problem/F

// Fight the good fight of the faith. Take hold of the 
// eternal life to which you were called when you made 
// your good confession in the presence of many witnesses
// 1 Timonthy 6:12
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

#define INF 1000005
#define LINF 1000000000000000005ll
#define MAXN 250005

int n;
vii adj[MAXN];
vi deg[MAXN];
set<int> useful;
bool vis[MAXN];

vi cnt;
vll sm;
vi lc, rc;
vi rem;

struct ST {
    int rt;
    ST() {
        rt = -1;
    }
    void add(ll p, int x, int u = -1, int lo = 0, int hi = INF) {
        if (rt == -1) {
            if (rem.empty()) {
                rt = cnt.size();
                cnt.pb(0);
                sm.pb(0);
                lc.pb(-1);
                rc.pb(-1);
            } else {
                rt = rem.back();
                rem.pop_back();
                cnt[rt] = 0;
                sm[rt] = 0;
                lc[rt] = -1;
                rc[rt] = -1;
            }
        }
        if (u == -1) {
            u = rt;
        }
        if (lo == hi) {
            cnt[u] += x;
            sm[u] += x * p;
            if (u != rt && cnt[u] == 0) {
                rem.pb(u);
            }
            return;
        }
        int mid = lo + hi >> 1;
        if (p <= mid) {
            if (lc[u] == -1) {
                if (rem.empty()) {
                    lc[u] = cnt.size();
                    cnt.pb(0);
                    sm.pb(0);
                    lc.pb(-1);
                    rc.pb(-1);
                } else {
                    lc[u] = rem.back();
                    rem.pop_back();
                    cnt[lc[u]] = 0;
                    sm[lc[u]] = 0;
                    lc[lc[u]] = -1;
                    rc[lc[u]] = -1;
                }
            }
            add(p, x, lc[u], lo, mid);
        } else {
            if (rc[u] == -1) {
                if (rem.empty()) {
                    rc[u] = cnt.size();
                    cnt.pb(0);
                    sm.pb(0);
                    lc.pb(-1);
                    rc.pb(-1);
                } else {
                    rc[u] = rem.back();
                    rem.pop_back();
                    cnt[rc[u]] = 0;
                    sm[rc[u]] = 0;
                    lc[rc[u]] = -1;
                    rc[rc[u]] = -1;
                }
            }
            add(p, x, rc[u], mid + 1, hi);
        }
        if (lc[u] != -1 && cnt[lc[u]] == 0) {
            lc[u] = -1;
        }
        if (rc[u] != -1 && cnt[rc[u]] == 0) {
            rc[u] = -1;
        }
        cnt[u] = (lc[u] == -1 ? 0 : cnt[lc[u]]) + (rc[u] == -1 ? 0 : cnt[rc[u]]);
        sm[u] = (lc[u] == -1 ? 0 : sm[lc[u]]) + (rc[u] == -1 ? 0 : sm[rc[u]]);
        if (u != rt && cnt[u] == 0) {
            rem.pb(u);
        }
    }
    ll qry(int k, int u = -1, int lo = 0, int hi = INF) {
        if (u == -1) {
            u = rt;
        }
        if (lo == hi) {
            return (ll) lo * k;
        }
        assert(u != -1);
        if (cnt[u] == k) {
            return sm[u];
        }
        int mid = lo + hi >> 1;
        if (lc[u] == -1) {
            return qry(k, rc[u], mid + 1, hi);
        }
        if (cnt[lc[u]] >= k) {
            return qry(k, lc[u], lo, mid);
        } else {
            return qry(k - cnt[lc[u]], rc[u], mid + 1, hi) + sm[lc[u]];
        }
    }
} st[MAXN];

int k;
// first is never close parent, second is close parent
pll dp(int u, int p) {
    vll vec;
    ll cur = 0;
    int sze = st[u].rt == -1 ? 0 : cnt[st[u].rt];
    for (auto [v, w] : adj[u]) {
        if (v == p) continue;
        if (useful.find(v) == useful.end()) break;
        vis[v] = 1;
        auto [a, b] = dp(v, u);
        b += w;
        if (b - a < 0) {
            cur += b;
        } else {
            debug("  +%lld\n", b - a);
            vec.pb(b - a);
            cur += a;
            sze++;
        }
    }
    debug(" %d %d %lld\n", u, sze, cur);
    for (ll i : vec) {
        st[u].add(i, 1);
    }
    auto solve = [&] (int k) {
        if (sze <= k) {
            return cur;
        }
        int x = sze - k;
        return cur + st[u].qry(x);
    };
    ll ra = solve(k - 1), rb = solve(k);
    for (ll i : vec) {
        st[u].add(i, -1);
    }
    return MP(ra, rb);
}

vll minimum_closure_costs() {
    scanf("%d", &n);
    vll ans(n, 0);
    REP (i, 0, n - 1) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        u--; v--;
        adj[u].pb(MP(v, w));
        adj[v].pb(MP(u, w));
        ans[0] += w;
    }
    REP (i, 0, n) {
        sort(ALL(adj[i]), [&] (ii l, ii r) {
                return adj[l.FI].size() > adj[r.FI].size();
                });
    }
    REP (i, 0, n) {
        deg[adj[i].size()].pb(i);
    }
    RREP (k, n - 1, 1) {
        ::k = k;
        debug("%d\n", k);
        for (int i : deg[k + 1]) {
            useful.insert(i);
            for (auto [u, w] : adj[i]) {
                if (useful.find(u) != useful.end()) {
                    st[u].add(w, -1);
                } else {
                    st[i].add(w, 1);
                }
            }
        }
        for (int i : useful) {
            if (vis[i]) continue;
            vis[i] = 1;
            auto [a, b] = dp(i, -1);
            ans[k] += b;
        }
        for (int i : useful) {
            vis[i] = 0;
        }
    }
    return ans;
}

int main() {
    vll ans = minimum_closure_costs();
    for (ll i : ans) {
        printf("%lld ", i);
    }
cerr << "hi" << "\n";
    printf("\n");
    return 0;
}