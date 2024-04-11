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

int t, n, k;
vi a, ans, order, freq;
vvi loc;

void solve() {
    cin >> n >> k;
    a.rsz(n); ans.clear(); ans.rsz(n, 0); loc.clear(); loc.rsz(n); freq.clear(); freq.rsz(n, 0); order.clear();
    F0R(i, n) {cin >> a[i]; a[i]--; freq[a[i]]++; loc[a[i]].pb(i);}
    F0R(i, n) {
        F0R(j, min(k, freq[i])) order.pb(i);
    }
    while (order.size()%k != 0) order.pop_back();
    F0R(i, k) {
        for (int j = i; j < order.size(); j += k) {
            int x = order[j];
            int y = loc[x].back();
            loc[x].pop_back();
            ans[y]=i+1;
        }
    }
    F0R(i, n) cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}