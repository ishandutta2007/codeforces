#include <bits/stdc++.h>
using namespace std;

void solve(){
	using ll = long long;
	int n;
	cin >> n;
	vector<ll> a(n);
	for(ll& x : a) cin >> x;
	ll asum = 0;
	for(ll x : a) asum += x;
	if(asum % n != 0){
		cout << -1 << '\n';
		return;
	}
	int ops = (n-1) * 3;
	cout << ops << '\n';
	for(int i = 1; i < n; i++){
		ll v = i+1;
		ll need = (v - (a[i] % v)) % v;
		cout << 1 << ' ' << v << ' ' << need << '\n';
		a[0] -= need;
		a[i] += need;
		assert(a[i] % v == 0);
		cout << v << ' ' << 1 << ' ' << a[i] / v << '\n';
		a[0] += a[i];
		a[i] = 0;
	}
	assert(a[0] == asum);
	for(int i = 1; i < n; i++){
		cout << 1 << ' ' << i+1 << ' ' << (asum / n) << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}