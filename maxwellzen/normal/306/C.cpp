#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pi> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define mp make_pair
#define F first
#define S second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll MOD = 1e9+9;// 998244353;

ll mod_exp(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b&1) r = (r*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }
    return r;
}

ll inv(ll a) {
    return mod_exp(a, MOD-2);
}

ll n, w, b;
vll fact;

ll choose(ll n, ll m) {
    m = min(m, n-m);
    if (m<0) return 0;
    ll num = fact[n], den = (fact[m] * fact[n-m])%MOD;
    return (num*inv(den))%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> w >> b;
    fact.rsz(max(w, b)+1);
    fact[0]=1;
    FOR(i, 1, fact.size()) fact[i] = (fact[i-1]*i)%MOD;
    ll ans = 0;
    FOR(j, 1, b+1) {
        if (n-j > w) continue;
        if (j > b) continue;
        ll add = (choose(b-1, j-1)*choose(w-1, n-j-1))%MOD;
        add = (add * max(0, (int)n-1-j))%MOD;
        ans = (ans + add)%MOD;
    }
    ans = (ans * fact[w])%MOD;
    ans = (ans * fact[b])%MOD;
    cout << ans << endl;
}