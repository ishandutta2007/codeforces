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

const ll INFLL = 1e18;
const int MAXN = 1e6 + 100;
const ll INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;

ll dist(pii x, pii y) {
    return 1ll * (x.fi - y.fi) * (x.fi - y.fi) + 1ll * (x.se - y.se) * (x.se - y.se);
}

bool check(pii x, pii y, pii z) {
    return dist(x, z) < dist(x, y) + dist(y, z);
}

void solve() {
    int n;
    cin >> n;
    vector<pii > a(n);
    rep(i, n)cin >> a[i].fi >> a[i].se;
    vector<int> p(n);
    iota(all(p), 0);
    mt19937 rng(228);
    while (true) {
//        cout<<"ajja\n";
        bool koko = true;
        shuffle(all(p), rng);
        for (int i = 0; i + 2 < n; i++) {
            int sw = i + 3;
            bool f=false;
            while (true) {
                if (check(a[p[i]], a[p[i + 1]], a[p[i + 2]])) {
                    f=true;
                    break;
                }
                if (sw == n)
                    break;
                swap(p[i + 2], p[sw++]);
            }
            if (!f) {
                koko = false;
                break;
            }
        }
        if (koko)
            break;
    }
    for (auto to:p)
        cout << to + 1 << " ";
    cout << '\n';
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
//    cin>>_t;
    while (_t--)
        solve();
#ifdef Mip182
    cout << '\n' << "Time : " << (double) (clock()) / CLOCKS_PER_SEC << '\n';
#endif
}