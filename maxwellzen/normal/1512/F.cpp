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
ll c;
vll a, b, d, r;
 
void solve() {
    cin >> n >> c;
    a.rsz(n); b.rsz(n-1); d.rsz(n); r.rsz(n);
    d[0]=r[0]=0;
    F0R(i, n) cin >> a[i];
    F0R(i, n-1) cin >> b[i];
    F0R(i, n-1) {
        d[i+1]=(b[i]-r[i]+a[i]-1)/a[i];
        r[i+1]=r[i]+a[i]*d[i+1]-b[i];
        d[i+1] += d[i]+1;
    }
    ll ans = INT_MAX;
    F0R(i, n) {
        ans=min(ans, d[i]+(c-r[i]+a[i]-1)/a[i]);
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