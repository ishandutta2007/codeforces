#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;
typedef vector<pair<int,int>> vpi;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define pi pair<int, int>
#define mp make_pair
#define F first
#define S second

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

int t, n, p;
vi a;
ll ans;
set<pi> s;
 
void solve() {
    cin >> n >> p;
    DSU d(n);
    a.rsz(n);
    s.clear();
    F0R(i, n) {
        cin >> a[i];
        if (a[i]<p) s.insert(mp(a[i], i));
    }
    ans=0;
    while (! s.empty()) {
        pi cur = *s.begin();
        s.erase(s.begin());
        int l=cur.S-1, m=cur.S, r=cur.S+1, x=cur.F;
        if (d.size(m)>1) continue;
        while (l>=0 && d.get(l)!=d.get(m) && a[l]%x==0) {
            ans += x;
            d.unite(l, m);
            l--;
        }
        while (r<n && d.get(r)!=d.get(m) && a[r]%x==0) {
            ans += x;
            d.unite(r, m);
            r++;
        }
    }
    F0R(i, n) if (d.get(i)!=d.get(0)) {
        ans += p;
        d.unite(i, 0);
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