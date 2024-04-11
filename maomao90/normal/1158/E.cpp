// problem-url: https://codeforces.com/problemset/problem/1158/E

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

vi device_operation(vi d) {
    int n = SZ(d);
    cout << '?';
    REP (i, 0, n) {
        cout << ' ' << d[i];
    }
    cout << endl;
    string s; cin >> s;
    vi res(n, 0);
    REP (i, 0, n) {
        res[i] = s[i] - '0';
    }
    return res;
}

vi find_tree(int n, int t) {
    cerr << "HI\n";
    vector<tuple<int, int, vi>> blk;
    vi all(n - 1, 0);
    iota(ALL(all), 1);
    blk.pb({1, n - 1, all});
    vector<vi> mpd(n);
    mpd[0] = vi(1, 0);
    while (!blk.empty()) {
        vector<tuple<int, int, vi>> nblk;
        REP (z, 0, 2) {
            vi d(n, 0);
            for (int i = z; i < SZ(blk); i += 2) {
                auto [l, r, v] = blk[i];
                if (l > r) {
                    continue;
                }
                int m = l + r >> 1;
                for (int u : mpd[l - 1]) {
                    d[u] = m - l + 1;
                }
            }
            vi on = device_operation(d);
            d = vi(n, 0);
            for (int i = z; i < SZ(blk); i += 2) {
                auto [l, r, v] = blk[i];
                if (l > r) {
                    continue;
                }
                int m = l + r >> 1;
                for (int u : mpd[l - 1]) {
                    d[u] = m - l;
                }
            }
            vi off = device_operation(d);
            for (int i = z; i < SZ(blk); i += 2) {
                auto [l, r, v] = blk[i];
                if (l > r) {
                    continue;
                }
                int m = l + r >> 1;
                vi lft, rht;
                for (int u : v) {
                    if (on[u] && !off[u]) {
                        mpd[m].pb(u);
                    } else if (off[u]) {
                        lft.pb(u);
                    } else {
                        assert(!on[u]);
                        rht.pb(u);
                    }
                }
                nblk.pb({l, m - 1, lft});
                nblk.pb({m + 1, r, rht});
            }
        }
        blk = nblk;
    }
    vi ans(2 * n - 2, 0);
    REP (i, 0, n) {
        cerr << i << '\n';
        for (int u : mpd[i]) {
            cerr << ' ' << u;
        }
        cerr << '\n';
    }
    vi p(n, 0);
    for (int u : mpd[1]) {
        p[u] = 0;
    }
    REP (z, 0, 3) {
        vector<pair<vi, vi>> blk;
        for (int l = (z == 2 ? 2 : z + 3); l < n; l += 3) {
            vi bt, tp;
            for (int u : mpd[l]) {
                bt.pb(u);
            }
            for (int u : mpd[l - 1]) {
                tp.pb(u);
            }
            blk.pb({bt, tp});
        }
        while (!blk.empty()) {
            vector<pair<vi, vi>> nblk;
            vi d(n, 0);
            for (auto [bt, tp] : blk) {
                if (bt.empty()) {
                    continue;
                }
                if (tp.empty()) {
                    assert(bt.empty());
                    continue;
                }
                if (SZ(tp) == 1) {
                    for (int u : bt) {
                        p[u] = tp[0];
                    }
                    continue;
                }
                int m = SZ(tp) / 2;
                REP (i, 0, m) {
                    d[tp[i]] = 1;
                }
            }
            vi on = device_operation(d);
            for (auto [bt, tp] : blk) {
                if (bt.empty()) {
                    continue;
                }
                if (tp.empty()) {
                    assert(bt.empty());
                    continue;
                }
                if (SZ(tp) == 1) {
                    continue;
                }
                int m = SZ(tp) / 2;
                vi lbt, rbt, ltp, rtp;
                for (int u : bt) {
                    if (on[u]) {
                        lbt.pb(u);
                    } else {
                        rbt.pb(u);
                    }
                }
                REP (i, 0, m) {
                    ltp.pb(tp[i]);
                }
                REP (i, m, SZ(tp)) {
                    rtp.pb(tp[i]);
                }
                nblk.pb({lbt, ltp});
                nblk.pb({rbt, rtp});
            }
            blk = nblk;
        }
    }
    REP (i, 1, n) {
        cerr << i + 1 << ": " << p[i] + 1 << '\n';
        ans[2 * (i - 1)] = i + 1;
        ans[2 * (i - 1) + 1] = p[i] + 1;
    }
    return ans;
}

int main() {
    int n; cin >> n;
    vi ans = find_tree(n, 0);
    cout << "!" << endl;
    REP (i, 0, n - 1) {
        cout << ans[i * 2] << ' ' << ans[i * 2 + 1] << endl;
    }
}