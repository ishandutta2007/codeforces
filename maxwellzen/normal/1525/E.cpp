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

ll MOD = 998244353;
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

ll n, m;
vvi dist;
vi cond;
vll fact;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    fact.rsz(n+1);
    fact[0]=1;
    FOR(i, 1, n+1) fact[i]=(fact[i-1]*i)%MOD;
    dist.rsz(n, vi(m));
    F0R(i, n) F0R(j, m) cin >> dist[i][j];
    ll ans = (m * fact[n])%MOD;
    F0R(pt, m) {
        cond.clear();
        F0R(c, n) cond.pb(dist[c][pt]-1);
        sort(all(cond));
        ll remove = 1;
        F0R(i, n) {
            if (i>=cond[i]) {
                remove=0;
                break;
            }
            remove = (remove*(cond[i]-i))%MOD;
        }
        ans -= remove;
        if (ans<0) ans += MOD;
    }
    ans = (ans * inv(fact[n]))%MOD;
    cout << ans << '\n';
}