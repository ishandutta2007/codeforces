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

int t, n, g, z;
ll MOD = 998244353;
string s;
vb grouped;

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

ll choose(ll n, ll m) {
    m = min(m, n-m);
    if (m<0) return 0;
    ll num=1, den=1;
    for (int i = 1; i <= m; i++) den = (den*i)%MOD;
    for (int i = n-m+1; i <= n; i++) num = (num*i)%MOD;
    return (num*inv(den))%MOD;
}
 
void solve() {
    cin >> n >> s;
    grouped.clear(); grouped.rsz(n, false);
    g=z=0;
    FOR(i, 1, n) if (s[i]=='1' && s[i-1]=='1' && !grouped[i-1]) {
        grouped[i-1]=true;
        grouped[i]=true;
        g++;
    }
    F0R(i, n) if (s[i]=='0') z++;
    cout << choose(z+g, g) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}