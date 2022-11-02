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
ll mx, mn;
vll a, b;
 
void solve() {
    cin >> n;
    a.rsz(n); b.rsz(n);
    F0R(i, n) cin >> a[i]; F0R(i, n) cin >> b[i];
    mx=mn=b[0];
    F0R(i, n) mx=max(mx, a[i]);
    F0R(i, n) mn=min(mn, a[i]);
    ll l=mn-1, r=mx, ans=-1;
    while (l <= r) {
        ll m = l + (r-l)/2, sum=0;
        F0R(i, n) if (a[i]>m) sum += b[i];
        if (sum >= m) {
            ans=m;
            l=m+1;
        } else r=m-1;
    }
    ll s1=0, s2=0;
    F0R(i, n) {
        if (a[i]>ans) s1 += b[i];
        if (a[i]>ans+1) s2 += b[i];
    }
    // cout << ans << ' ' << s1 << ' ' << ans+1 << ' ' << s2 << '\n';
    cout << min(max(s1, ans), max(s2, ans+1)) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}