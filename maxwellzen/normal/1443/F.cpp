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

int t, n, k;
vi a, b, loc, bloc;
ll MOD = 998244353;
set<int> save;
 
void solve() {
    cin >> n >> k;
    save.clear();
    a.rsz(n); b.rsz(k); loc.rsz(n); bloc.rsz(k);
    F0R(i, n) {cin >> a[i]; a[i]--; loc[a[i]]=i;}
    F0R(i, k) {cin >> b[i]; b[i]--; save.insert(loc[b[i]]);}
    ll ans = 1;
    F0R(i, k) {
        int x = loc[b[i]];
        if ((x==0 || save.find(x-1)!=save.end()) && (x==n-1 || save.find(x+1)!=save.end())) {
            cout << 0 << '\n';
            return;
        } else {
            if ((x==0 || save.find(x-1)!=save.end()) || (x==n-1 || save.find(x+1)!=save.end())) ;
            else ans = (ans*2)%MOD;
            save.erase(x);
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