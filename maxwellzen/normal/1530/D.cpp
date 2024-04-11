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

int t, n;
vi a, b, nw;
map<int, vi> want;
 
void solve() {
    cin >> n;
    a.rsz(n); nw.clear(); nw.rsz(n, 0); b.clear(); b.rsz(n, -1); want.clear();
    F0R(i, n) {cin >> a[i]; a[i]--; want[a[i]].pb(i); nw[a[i]]++;}
    // F0R(i, n) cout << nw[i] << ' '; cout << '\n';
    int ans = 0;
    F0R(i, n) if (nw[i]>0) ans++;
    for (auto p : want) {
        // cout << p.F << ' '; for (int i : p.S) cout << i << ' '; cout << '\n';
        int mn = p.S[0];
        for (int i : p.S) if (nw[i]<nw[mn]) mn=i;
        b[mn]=p.F;
    }
    set<int> get, take, both;
    F0R(i, n) if (b[i]==-1 && nw[i]==0) both.insert(i);
    else if (b[i]==-1) take.insert(i);
    else if (nw[i]==0) get.insert(i);
    // cout << "Get: "; for (int i : get) cout << i << ' '; cout << '\n';
    // cout << "Take: "; for (int i : take) cout << i << ' '; cout << '\n';
    // cout << "Both: "; for (int i : both) cout << i << ' '; cout << '\n';
    while (both.size()+take.size()>0) {
        if (take.size()==0) {
            vi cycle;
            for (int i : both) cycle.pb(i);
            F0R(i, cycle.size()) b[cycle[i]]=cycle[(i+1)%cycle.size()];
            both.clear();
        } else {
            int i = *take.begin();
            take.erase(i);
            if (both.size()>0) {
                int j = *both.begin();
                both.erase(j);
                take.insert(j);
                b[i]=j;
            } else {
                int j = *get.begin();
                get.erase(j);
                b[i]=j;
            }
        }
    }
    cout << ans << '\n';
    F0R(i, n) cout << b[i]+1 << ' ';
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