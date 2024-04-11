#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve(){
	vector<ll> m = {0, 2, 3, 1};
	ll n;
	cin >> n;
	n--;
	ll which = n % 3;
	n /= 3;
	ll k = 0;
	while((1ll << (2*k)) <= n){
		n -= (1ll << (2*k));
		k++;
	}
	ll ans0 = (1ll << (2*k)) ^ n;
	ll ans1 = (1ll << (2*k+1));
	for(int j = 0; j < k; j++){
		ans1 ^= m[(3 & (n >> (2*j)))] << (2*j);
	}
	vector<ll> ret = {ans0, ans1, ans0 ^ ans1};
	cout << ret[which] << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}