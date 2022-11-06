#include <vector>
#include <iostream>
#include <algorithm>
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
vvi matrixPow(const vvi &a, ll p) {
    if (p == 0)
        return matrixUnit(a.size());
    if (p & 1)
        return matrixMul(a, matrixPow(a, p - 1));
    return matrixPow(matrixMul(a, a), p / 2);
}
int main() {
	ll b[108];
	ios_base::sync_with_stdio(false);
	ll n,k; cin>>n>>k;
	for (ll i=0;i<n;i++) cin>>b[i];
	vvi mat(n, vi(n));
	for (ll x=0;x<n;x++) {
		for (ll y=0;y<n;y++) {
			mat[x][y]=(0==(__builtin_popcountll(b[x]^b[y]))%3)?1:0;
		}
	}
	vvi res=matrixPow(mat,k-1);
	ll ans=0;
	for (ll x=0;x<n;x++) for (ll y=0;y<n;y++) ans=(ans+res[x][y])%MOD;
	cout<<ans<<endl;
}