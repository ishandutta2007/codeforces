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

int t;
ll n, m;
ll x, sum, mx;
vll a, p;

int bsearch(ll i) {
    int l=0, r=n-1, ans=-1;
    while (l <= r) {
        int mid = (l+r)/2;
        if (p[mid]>=i) {
            ans=mid;
            r=mid-1;
        } else l=mid+1;
    }
    return ans;
}
 
void solve() {
    cin >> n >> m;
    a.rsz(n); p.rsz(n);
    F0R(i, n) cin >> a[i];
    p[0]=a[0];
    FOR(i, 1, n) p[i]=a[i]+p[i-1];
    sum = p[n-1];
    p[0]=max(0LL, p[0]);
    FOR(i, 1, n) p[i]=max(p[i-1], p[i]);
    mx=p[n-1];
    F0R(i, m) {
        cin >> x;
        if (sum<=0 || x <= mx) {
            cout << bsearch(x) << ' ';
        } else {
            ll rot = (x-mx+sum-1)/sum;
            ll ans = n * rot;
            x -= sum*rot;
            ans += bsearch(x);
            cout << ans << ' ';
        }
    }
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