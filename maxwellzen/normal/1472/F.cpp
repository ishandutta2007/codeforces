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

int t, n, m, r, c;
map<int, vi> bl;
vpi b;

void solve() {
    cin >> n >> m;
    b.clear(); bl.clear();
    F0R(i, m) {
        cin >> r >> c;
        r--; c--;
        bl[c].pb(r);
    }
    for (auto p : bl) {
        if (p.S.size()==2) b.pb(mp(p.F, 2));
        else if (p.S.size()==1) b.pb(mp(p.F, p.S[0]));
    }
    sort(all(b));
    while (b.size()>0) {
        pi c1 = b.back();
        b.pop_back();
        if (c1.S==2) continue;
        pi c2 = b.back();
        b.pop_back();
        if (c2.S==2) {
            cout << "NO\n";
            return;
        }
        if (c1.S==c2.S && c1.F%2==c2.F%2) {
            cout << "NO\n";
            return;
        }
        if (c1.S != c2.S && c1.F%2 != c2.F%2) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}