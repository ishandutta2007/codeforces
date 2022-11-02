#include <bits/stdc++.h>

using namespace std;

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;

#define FOR(i,a,b) for (ll i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (ll i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define pi pair<int, int>
#define mp make_pair
#define F first
#define S second
const ll MOD = 1000000007;
int t;
ll x[500005], n, mods[61], cnts[61];

void solve() {
    cin >> n;
    F0R(i, n) cin >> x[i];
    F0R(i, 61) cnts[i]=0;
    F0R(i, n) {
        F0R(j, 61) {
            if (x[i] & (1LL<<j)) cnts[j]++;
        }
    }
//    for (int i = 0; i < 60; i++) cout << cnts[i] << ' ';
//    cout << '\n';
    ll ans = 0;
    F0R(i, n) {
        ll a=0, o=0;
        F0R(j, 61) {
            if (x[i] & (1LL<<j)) {
                a += (cnts[j]*mods[j])% MOD;
                a %= MOD;
                o += (n*mods[j])%MOD;
                o %= MOD;
            } else {
                o += (cnts[j]*mods[j])%MOD;
                o %= MOD;
            }
        }
        ans += a * o;
        ans %= MOD;
        if (ans < 0) ans += MOD;
    }
//    ans *= 250000002;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mods[0]=1;
    FOR(i, 1, 61) {
        mods[i] = (mods[i-1]*2)%MOD;
        if (mods[i]<0) mods[i] += MOD;
//        cout << mods[i] << ' ';
    }
//    cout << '\n';
    cin >> t;
    while (t--) {
        solve();
    }
}