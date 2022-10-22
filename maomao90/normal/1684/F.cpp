// time-limit: 2000
// problem-url: https://codeforces.com/contest/1684/problem/F

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
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
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
int n, m;
int a[MAXN];
int lr[MAXN];
map<int, int> occ, occ2, lst;
int nxt[MAXN];

int main() {
    cin >> t;
    while (t--) {
        occ.clear();
        cin >> n >> m;
        REP (i, 1, n + 1) {
            cin >> a[i];
        }
        lst.clear();
        RREP (i, n, 1) {
            nxt[i] = lst[a[i]];
            lst[a[i]] = i;
        }
        REP (i, 1, n + 1) {
            lr[i] = -1;
        }
        REP (i, 0, m) {
            int l, r; cin >> l >> r;
            mxto(lr[l], r);
        }
        int p = -1;
        vii segs, nsegs;
        REP (i, 1, n + 1) {
            if (lr[i] > p) {
                segs.pb(ii{i, lr[i]});
                p = lr[i];
            }
        }
        int cl = 0, cr = -1;
        occ.clear();
        int over = 0;
        for (auto [l, r] : segs) {
            while (cr < r) {
                cr++;
                if (occ[a[cr]]++ == 1) {
                    over++;
                }
            }
            while (cl < l) {
                if (occ[a[cl]]-- == 2) {
                    over--;
                }
                cl++;
            }
            if (over != 0) {
                nsegs.pb(ii{l, r});
                cerr << l << ' ' << r << '\n';
            }
        }
        cerr << '\n';
        segs = nsegs;
        int ans = n;
        if (segs.size() == 0) {
            ans = 0;
        } else if (segs.size() == 1) {
            ii lft = segs[0];
            int j = lft.SE;
            occ.clear();
            while (lft.FI <= j && occ[a[j]] == 0) {
                occ[a[j]]++;
                j--;
            }
            ans = j - lft.FI + 1;
            REP (i, lft.FI, lft.SE) {
                occ[a[i]]++;
                while (j < lft.SE && occ[a[i]] > 1) {
                    occ[a[++j]]--;
                }
                if (occ[a[i]] > 1) {
                    break;
                }
                mnto(ans, j - i);
            }
        } else {
            ii lft = segs[0], rht = segs.back();
            int j = rht.SE;
            occ.clear();
            occ2.clear();
            while (rht.FI <= j && occ[a[j]] == 0) {
                occ[a[j]]++;
                if (j <= lft.SE) {
                    occ2[a[j]]++;
                }
                j--;
            }
            ans = j - lft.FI + 1;
            int curr = 0;
            REP (i, lft.FI, lft.SE) {
                occ2[a[i]]++;
                while (j < rht.SE && occ2[a[i]] > 1) {
                    j++;
                    if (j <= lft.SE) {
                        occ2[a[j]]--;
                    }
                    occ[a[j]]--;
                }
                if (occ2[a[i]] > 1) {
                    break;
                }
                if (i >= rht.FI) {
                    occ[a[i]]++;
                    while (j < rht.SE && occ[a[i]] > 1) {
                        j++;
                        if (j <= lft.SE) {
                            occ2[a[j]]--;
                        }
                        occ[a[j]]--;
                    }
                    if (occ[a[i]] > 1) {
                        break;
                    }
                }
                mxto(curr, lr[i]);
                int u = i;
                while (curr >= nxt[u] && nxt[u] != 0) {
                    while (j < nxt[u]) {
                        j++;
                        if (j <= lft.SE) {
                            occ2[a[j]]--;
                        }
                        occ[a[j]]--;
                    }
                    u = nxt[u];
                }
                mnto(ans, j - i);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}