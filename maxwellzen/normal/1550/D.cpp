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
ll n, l, r, h;
ll ans, MOD=1e9+7;
vll fact;

ll mod_exp(ll a, ll b) {
    a %= MOD;
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

ll choose(ll a, ll b) {
    if (a<b) return 0;
    ll r = fact[a];
    r = (r * inv(fact[b]))%MOD;
    r = (r * inv(fact[a-b]))%MOD;
    return r;
}
 
void solve() {
    cin >> n >> l >> r;
    h = (n+1)/2;
    ll a = min(r-n, 1-l);
    ans = (a*choose(n, h))%MOD;
    if (n%2 != 0) ans = (2*ans)%MOD;
    int left=1, right=n;
    while (true) {
        a++;
        while (left-a<l) left++;
        while (right+a>r) right--;
        if (left>right+1) break;
        if (left-1>h) break;
        if (n-right>h) break;
        if (n%2==0) {
            ans = (ans + choose(right-left+1, h-(left-1)))%MOD;
        } else {
            ans = (ans + choose(right-left+1, h-(left-1)))%MOD;
            if (left<=h) ans = (ans + choose(right-left+1, h-1-(left-1)))%MOD;
        }
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact.rsz(200001);
    fact[0]=1;
    FOR(i, 1, fact.size()) fact[i]=(fact[i-1]*i)%MOD;
    cin >> t;
    while (t--) {
        solve();
    }
}