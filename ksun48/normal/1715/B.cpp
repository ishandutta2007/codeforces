#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
void solve(){
	ll n, k, b, s;
	cin >> n >> k >> b >> s;
	ll smin = b * k;
	ll smax = b * k + n * (k-1);
	if(s < smin || s > smax){
		cout << -1 << '\n';
		return;
	}
	vector<ll> a(n);
	a[0] += b * k;
	ll diff = s - smin;
	for(int i = 0; i < n; i++){
		a[i] += min(diff, k-1);
		diff -= min(diff, k-1);
	}
	for(ll x : a){
		cout << x << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}