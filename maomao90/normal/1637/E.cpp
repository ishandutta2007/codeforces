// time-limit: 2000
// problem-url: https://codeforces.com/contest/1637/problem/E

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
#define MAXN 300005

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int t;
int n, m;
int a[MAXN];
unordered_map<int, int, custom_hash> cnt, ord, adj[MAXN];
vi comp[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cnt.clear(); ord.clear();
        REP (i, 0, n) {
            adj[i].clear();
            comp[i].clear();
        }
        REP (i, 0, n) {
            cin >> a[i];
        }
        REP (i, 0, n) {
            cnt[a[i]]++;
        }
        sort(a, a + n);
        n = unique(a, a + n) - a;
        vi dc;
        REP (i, 0, n) {
            dc.pb(cnt[a[i]]);
            ord[a[i]] = i;
        }
        sort(ALL(dc));
        dc.erase(unique(ALL(dc)), dc.end());
        REP (i, 0, m) {
            int x, y; cin >> x >> y;
            adj[ord[x]][ord[y]] = 1;
            adj[ord[y]][ord[x]] = 1;
        }
        RREP (i, n - 1, 0) {
            comp[cnt[a[i]]].pb(i);
        }
        ll ans = 0;
        REP (i, 0, n) {
            for (int j : dc) {
                for (int k : comp[j]) {
                    if (k == i) continue;
                    if (!adj[i][k]) {
                        assert(cnt[a[k]] == j);
                        mxto(ans, (cnt[a[i]] + cnt[a[k]]) * (ll) (a[i] + a[k]));
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}