#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;

//   (  n  k   )
#define MAX 100100
const ll mod = 1e9+7;
ll fac[MAX+1];

void init(){
	fac[0] = 1;
	for(int i=1;i<=MAX;i++) fac[i] = (fac[i-1] * i) % mod;
}
ll pw(ll n, ll k){
    if(!k) return 1;
    ll re = pw(n, k/2) % mod;
    return re * re % mod * (k % 2 ? n : 1) % mod;
}
//  :  X  O
ll P(ll n, ll k){
	return fac[n] * pw(fac[n-k], mod-1) % mod;
}
//   :  O  O
ll U(ll n, ll k){
	return pw(n, k) % mod;
}
//  :  X  X
ll C(ll n, ll k){
	return fac[n] * pw(fac[k], mod-2) % mod * pw(fac[n-k], mod-2) % mod;
}
//   :  O  X 
ll H(ll n, ll k){
	return C(n+k-1, k);
}

void solve(){
	cin >> n >> k;

	ll ans = 1;

	for(int i=1;i<=k;i++) ans = (ans * n) % mod;

	cout << ans;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	init();

	int tc = 1; cin >> tc;
	while(tc--) solve(), cout << "\n";
}