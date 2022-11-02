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

int t, k, n, m, aind, bin;
vi a, b, ans;
bool stop;
 
void solve() {
    cin >> k >> n >> m;
    a.rsz(n); b.rsz(m);
    F0R(i, n) cin >> a[i];
    F0R(i, m) cin >> b[i];
    ans.clear();
    stop=false;
    aind=bin=0;
    while (ans.size()<n+m) {
        stop=true;
        while (aind<n && a[aind]<=k) {
            ans.pb(a[aind]);
            if (a[aind]==0) k++;
            aind++;
            stop=false;
        }
        while (bin<m && b[bin]<=k) {
            ans.pb(b[bin]);
            if (b[bin]==0) k++;
            bin++;
            stop=false;
        }
        if (stop) break;
    }
    if (aind<n || bin<m) cout << -1;
    else for (int i : ans) cout << i << ' ';
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