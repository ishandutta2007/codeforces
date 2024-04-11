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

int t, n, m, a, b;
vi p, q, c;
vvi adj;

bool dfs(int i, int color) {
    c[i]=color;
    for (int nb : adj[i]) if (c[nb]==c[i]) return false;
    for (int nb : adj[i]) if (c[nb]==0) if (!dfs(nb, 3-color)) return false;
    return true;
}
 
void solve() {
    cin >> n >> m;
    adj.clear();
    adj.rsz(n);
    p.rsz(n); q.rsz(n);
    F0R(i, n) cin >> p[i];
    F0R(i, n) cin >> q[i];
    F0R(i, m) {
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    c.clear();
    c.rsz(n, 0);
    if (dfs(0, 1)) {
        ll s1=0, s2=0;
        F0R(i, n) if (c[i]==1) s1 += p[i]-q[i]; else s2 += p[i]-q[i];
        if (s1==s2) cout << "YES\n"; else cout << "NO\n";
    } else {
        ll s=0;
        F0R(i, n) s += p[i]-q[i];
        if (s%2==0) cout << "YES\n"; else cout << "NO\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}