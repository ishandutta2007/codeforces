#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
typedef vector<ll> vi;
typedef vector<vi> vvi;
vvi matrixUnit(ll n) {
    vvi res(n, vi(n));
    for (ll i = 0; i < n; i++)
        res[i][i] = 1;
    return res;
}
vvi matrixMul(const vvi &a, const vvi &b) {
    ll n = a.size();
    ll m = a[0].size();
    ll k = b[0].size();
    vvi res(n, vi(k));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < k; j++)
            for (ll p = 0; p < m; p++)
                res[i][j] = (res[i][j] + (long long) a[i][p] * b[p][j]) % MOD;
    return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	ll k; cin>>k;
	ll po=MOD-1;
	ll pt=2;
	for (ll i=0;i<k;i++) {
		ll e; cin>>e;
		pt=mod_pow(pt,e,MOD);
		po=mod_pow(po,e,MOD);
	}
	po=(po*mod_inv(MOD-1,MOD))%MOD;
	pt=(pt*mod_inv(2LL,MOD))%MOD;
	vvi m(2, vi(2));
	vvi J(2, vi(2));
	vvi mi(2, vi(2));
	m[0][0]=MOD-1; m[0][1]=2;
	m[1][0]=1; m[1][1]=1;
	J[0][0]=po; J[0][1]=0;
	J[1][0]=0; J[1][1]=pt;
	mi[0][0]=MOD-1; mi[0][1]=2;
	mi[1][0]=1; mi[1][1]=1;
	for (ll i=0;i<2;i++) for (ll j=0;j<2;j++) {
		mi[i][j]=(mi[i][j]*mod_inv(3LL,MOD))%MOD;
	}
	vvi res=matrixMul(m,matrixMul(J,mi));
	ll numer=res[1][0];
	ll denom=pt;
	cout<<numer<<"/"<<denom<<endl;
}