#include <bits/stdc++.h>

using namespace std;

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
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
ll cx, cy;
vll byx, byy;

void solve() {
    cin >> n;
    byx.clear();
    byy.clear();
    F0R(i, 2*n) {
        cin >> cx >> cy;
        if (cx==0) {
            byy.pb(abs(cy));
        } else {
            byx.pb(abs(cx));
        }
    }
    sort(all(byx));
    sort(all(byy));
    long double ans = 0;
    F0R(i, n) {
        ll squared = byx[i]*byx[i] + byy[i]*byy[i];
        ans += sqrt((long double)squared);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(17);
    cin >> t;
    while (t--) {
        solve();
    }
}