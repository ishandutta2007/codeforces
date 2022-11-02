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

struct DSU {
    vector<int> e;
    DSU(int N) { e = vector<int>(N, -1); }
    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool same_set(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x;
        return true;
    }
};

int n, m, t;
vvi vecs;
vi ans;
vb toggle;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vecs.rsz(n);
    DSU d(m+1);
    F0R(i, n) {
        cin >> t;
        vecs[i].rsz(t);
        F0R(j, t) {cin >> vecs[i][j]; vecs[i][j];}
    }
    ll cnt = 1;
    F0R(i, n) {
        int x = vecs[i][0], y = (vecs[i].size()==1 ? 0 : vecs[i][1]);
        if (d.same_set(x, y)) continue;
        cnt = (cnt*2)%MOD;
        d.unite(x, y);
        ans.pb(i+1);
    }
    cout << cnt << ' ' << ans.size() << '\n';
    F0R(i, ans.size()) cout << ans[i] << ' ';
    cout << '\n';
}