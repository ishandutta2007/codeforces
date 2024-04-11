// time-limit: 2000
// problem-url: https://codeforces.com/contest/1582/problem/G

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
#define MAXN 1000005
#define LOG 19

int n;
int a[MAXN];
string b;
int lp[MAXN];
vi pos[MAXN];
int r[MAXN];
int mn[MAXN * LOG * 2];
vii events[MAXN];
map<int, int> mp;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    REP (i, 2, MAXN) {
        lp[i] = i;
    }
    REP (i, 2, MAXN) {
        if (lp[i] != i) continue;
        for (ll j = (ll) i * i; j < MAXN; j += i) {
            mnto(lp[j], i);
        }
    }
    cin >> n;
    REP (i, 0, n) {
        cin >> a[i];
    }
    cin >> b;
    REP (i, 0, n) {
        while (a[i] > 1) {
            pos[lp[a[i]]].pb(i);
            a[i] /= lp[a[i]];
        }
    }
    REP (i, 0, n + 1) {
        r[i] = n;
    }
    REP (i, 0, MAXN * 2 * LOG) {
        mn[i] = INF;
    }
    REP (i, 2, MAXN) {
        if (pos[i].empty()) continue;
        int k = pos[i].size();
        cerr << i << ' ' << k << '\n';
        vi psm(k + 1, 0);
        REP (j, 0, k) {
            psm[j + 1] = b[pos[i][j]] == '*' ? 1 : -1;
            psm[j + 1] += psm[j];
        }
        pos[i].pb(n);
        RREP (j, k, 1) {
            mn[psm[j] + n * LOG] = pos[i][j - 1];
            cerr << psm[j] << " -> " << pos[i][j - 1] << '\n';
            int x = mn[psm[j - 1] - 1 + n * LOG];
            cerr << ' ' << x << '\n';
            if (x != INF) {
                //mnto(r[pos[i][j - 1]], x);
                events[j - 2 < 0 ? 0 : pos[i][j - 2] + 1].pb(MP(x, 1));
                events[pos[i][j - 1] + 1].pb(MP(x, 0));
                //cerr << "upd " << (j - 2 < 0 ? 0 : pos[i][j - 2] + 1) << ' ' << pos[i][j - 1] << '\n';
            }
        }
        RREP (j, k, 1) {
            mn[psm[j] + n * LOG] = INF;
        }
    }
    ll ans = 0;
    REP (l, 0, n) {
        //cerr << "  " << l << ' ' << events[l].size() << '\n';
        for (auto a : events[l]) {
            //cerr << "    " << a.FI << ' ' << a.SE << '\n';
            if (a.SE == 1) {
                mp[a.FI]++;
            } else {
                if (--mp[a.FI] == 0) {
                    mp.erase(a.FI);
                }
            }
        }
        r[l] = mp.empty() ? n : mp.begin() -> FI;
        cerr << l << ' ' << r[l] << '\n';
        ans += r[l] - l;
    }
    cout << ans << '\n';
    return 0;
}