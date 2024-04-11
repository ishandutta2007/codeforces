#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	for(ll& x : a) cin >> x;
	for(ll& x : b) cin >> x;
	ll asum = 0;
	ll bsum = 0;
	for(ll x : a) asum += x;
	for(ll x : b) bsum += x;
	if(asum > bsum){
		cout << "NO" << '\n';
		return;
	}
	ll lmax = 0;
	ll lsum = 0;
	ll rsum = b.back();
	for(int i = 0; i < 2*n; i++){
		rsum += -a[i%n] + b[i%n];
		lsum += -a[i%n] + b[(i+n-1)%n];
		lmax = max(lmax, lsum);
		if(rsum < lmax){
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}