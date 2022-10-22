// time-limit: 1500
// problem-url: https://codeforces.com/contest/1641/problem/C

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

int n, q;
set<ii> st;

int p[MAXN], rnk[MAXN], mn[MAXN], mx[MAXN];
int findp(int a) {
    if (p[a] == a) return a;
    return p[a] = findp(p[a]);
}
void join(int a, int b) {
    int pa = findp(a), pb = findp(b);
    if (pa == pb) return;
    if (rnk[pa] < rnk[pa]) swap(pa, pb);
    if (rnk[pa] == rnk[pb]) rnk[pa]++;
    p[pb] = pa;
    mxto(mx[pa], mx[pb]);
    mnto(mn[pa], mn[pb]);
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n >> q;
    REP (x, 0, n + 2) {
        p[x] = x;
        rnk[x] = 1;
        mn[x] = x;
        mx[x] = x;
    }
    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            int l, r, x; cin >> l >> r >> x;
            if (x == 0) {
                while (1) {
                    int p = findp(l);
                    if (mx[p] > r) {
                        break;
                    } else {
                        join(l, mx[p] + 1);
                    }
                }
            } else {
                auto lo = st.lower_bound(MP(l, -1));
                if (lo != st.end() && lo -> SE <= r) {
                    continue;
                } else if (lo != st.end() && lo -> FI == l && lo -> SE >= r) {
                    st.erase(lo);
                }
                lo = st.insert(MP(l, r)).FI;
                while (lo != st.begin() && prev(lo) -> SE >= r) {
                    st.erase(prev(lo));
                }
            }
        } else {
            int j; cin >> j;
            if (mx[findp(j)] > j) {
                cout << "NO\n";
                continue;
            }
            int cmn = mn[findp(j - 1)];
            if (mx[findp(j - 1)] == j - 1) {
                cmn = j;
            }
            int cmx = mx[findp(j + 1)] - 1;
            cerr << cmn << ' ' << cmx << '\n';
            int lo = cmn, hi = j, mid;
            bool pos = 0;
            while (lo <= hi) {
                mid = lo + hi >> 1;
                auto ptr = st.lower_bound(MP(mid, -1));
                if (ptr != st.end() && ptr -> SE >= j && ptr -> SE <= cmx 
                        && ptr -> FI <= j && ptr -> FI >= cmn) {
                    pos = 1;
                    break;
                } else if (ptr != st.end() && ptr -> SE < j) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            if (pos) {
                cout << "YES\n";
            } else {
                cout << "N/A\n";
            }
        }
    }
    return 0;
}