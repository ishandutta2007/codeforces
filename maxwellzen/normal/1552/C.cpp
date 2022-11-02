#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pi> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define mp make_pair
#define F first
#define S second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll MOD = 1e9+7;// 998244353;

int t, n, k, x, y;
vpi e;
set<int> s;
vi v;

void solve() {
    e.clear();
    cin >> n >> k;
    s.clear(); v.clear();
    F0R(i, 2*n) s.insert(i+1);
    F0R(i, k) {
        cin >> x >> y;
        s.erase(x); s.erase(y);
        e.pb(mp(min(x, y), max(x, y)));
    }
    for (int i : s) v.pb(i);
    F0R(i, v.size()/2) e.pb(mp(v[i], v[i+n-k]));
    int ans = 0;
    F0R(j, e.size()) F0R(i, j) {
        if (e[i].F<e[j].F && e[j].F<e[i].S && e[i].S<e[j].S) {
            ans++;
        }
        else if (e[i].F>e[j].F && e[i].F<e[j].S && e[i].S>e[j].S) {
            ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}