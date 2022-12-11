#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int, int> >
#define vpll vector <pair <long long, long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout << #x << "=" << x << ", ";}
#define in(x); { for (auto &to : x) cin >> to;}
#define out(x); { for (auto &to : x) cout << to << " "; cout << '\n'; }

template<class T>
bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }

template<class T>
bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const ll INFLL = 1e18;
const int MAXN = 1e6 + 100;
const ll INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;

void solve() {
    int n;
    cin >> n;
    map<int, vpii > m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 2; j * j <= x; j++) {
            if (x % j)
                continue;
            int f = 1;
            while (x % j == 0)
                f *= j, x /= j;
            m[j].pb({f, i});
        }
        if (x > 1)
            m[x].pb({x, i});
    }
    int ans = 0;
//    cout << m.size() << '\n';
    for (auto &to:m) {
//        cout << "to " << to.fi << '\n';
        int mx = 0;
        sort(all(to.se));
        if (to.se.size() < n) {
//            cout << to.fi << '\n';
            sort(all(to.se), [&](pii x, pii y) {
                return x.se < y.se;
            });
//            for (auto too:to.se)
//                cout << too.se << " ";
//            cout << '\n';
            int was = -123;
            int cnt = 0;
            for (auto too:to.se) {
                if ((was + 1) % n == too.se || cnt == 0) {
                    cnt++;
                    uax(mx, cnt);
                } else
                    cnt = 1, uax(mx, cnt);
                was = too.se;
            }
            for (auto too:to.se) {
                if ((was + 1) % n == too.se || cnt == 0) {
                    cnt++;
                    uax(mx, cnt);
                } else
                    cnt = 1, uax(mx, cnt);
                was = too.se;
            }
//            cout << mx << '\n';
        } else {
//            cout << "ahah\n";
            vector<pii > bad;
            int ind = 0;
            while (ind < n && to.se[ind].fi == to.se[0].fi)
                ind++;
            while (ind < n)
                bad.pb(to.se[ind++]);
            sort(all(bad), [&](pii x, pii y) {
                return x.se < y.se;
            });
//            for (auto too:bad)
//                cout << too.se << " ";
//            cout << '\n';
            int was = -1;
            int cnt = 0;
            if (!bad.empty()) {
                for (auto too:bad) {
                    if ((was + 1) % n == too.se || cnt == 0) {
                        cnt++;
                        uax(mx, cnt);
                    } else
                        cnt = 1, uax(mx, cnt);
                    was = too.se;
                }
//                cout << cnt << " " << was << '\n';
                for (auto too:bad) {
                    if ((was + 1) % n == too.se || cnt == 0) {
                        cnt++;
                        uax(mx, cnt);
                    } else
                        cnt = 1, uax(mx, cnt);
                    was = too.se;
                }
//                cout << mx << '\n';
            }
        }
//        cout << mx << '\n';
        uax(ans, mx);
    }
    cout << ans << '\n';
}

int main() {
#ifdef Mip182
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int _t;
    _t = 1;
    cin >> _t;
    while (_t--)
        solve();
#ifdef Mip182
    cout << '\n' << "Time : " << (double) (clock()) / CLOCKS_PER_SEC << '\n';
#endif
}