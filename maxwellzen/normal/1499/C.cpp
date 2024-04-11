#include <bits/stdc++.h>

using namespace std;

using namespace std;
typedef long long ll;
typedef vector<int> vi;
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
vector<ll> a, b, c;

void solve() {
    cin >> n;
    c.rsz(n);
    F0R(i, n) cin >> c[i];
    a.clear();
    b.clear();
    F0R(i, n) {
        if (i%2==0) a.pb(c[i]);
        else b.pb(c[i]);
    }
    ll asum=0, bsum=0, amin, bmin;
    ll aans[a.size()], bans[a.size()];
    amin=bmin=LLONG_MAX;
    F0R(i, a.size()) {
        asum += a[i];
        amin = min(amin, a[i]);
        aans[i] = asum+amin*(n-i-1);
    }
    F0R(i, b.size()) {
        bsum += b[i];
        bmin = min(bmin, b[i]);
        bans[i] = bsum+bmin*(n-i-1);
    }
    ll ans = LLONG_MAX;
    F0R(i, a.size()) {
        if (i<b.size()) ans = min(ans, aans[i]+bans[i]);
        if (i-1>=0 && i-1<b.size()) ans = min(ans, aans[i]+bans[i-1]);
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