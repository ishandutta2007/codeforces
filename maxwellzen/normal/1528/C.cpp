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

int t, n, p, ans, tim;
vvi a, adj;
vi st, ed;
set<pi> cliq;

void dfs(int i, int parent) {
    st[i]=tim++;
    for (int nb : adj[i]) if (nb!=parent) dfs(nb, i);
    ed[i]=tim-1;
}

void init(int root) {
    tim=0;
    st.rsz(n), ed.rsz(n);
    dfs(root, root);
}

bool anc(int i, int j) {return st[i]<=st[j] && ed[i]>=ed[j];}

void dfs2(int i, int parent) {
    auto it = cliq.upper_bound(mp(st[i], i));
    bool replace=false;
    pi toreplace;
    if (it==cliq.end() || !anc(i, (*it).S)) {
        it = cliq.lower_bound(mp(st[i], i));
        if (it==cliq.begin() || !anc((*--it).S, i)) cliq.insert(mp(st[i], i));
        else {
            replace=true;
            toreplace=*it;
            cliq.erase(it);
            cliq.insert(mp(st[i], i));
        }
    }
    ans=max(ans, (int)cliq.size());
    for (int nb : a[i]) if (nb != parent) dfs2(nb, i);
    cliq.erase(cliq.find(mp(st[i], i)));
    if (replace) cliq.insert(toreplace);
}
 
void solve() {
    cin >> n;
    a.clear(); adj.clear();
    a.rsz(n); adj.rsz(n);
    F0R(i, n-1) {
        cin >> p;
        a[p-1].pb(i+1);
        a[i+1].pb(p-1);
    }
    F0R(i, n-1) {
        cin >> p;
        adj[p-1].pb(i+1);
        adj[i+1].pb(p-1);
    }
    init(0);
    ans=0;
    dfs2(0, 0);
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