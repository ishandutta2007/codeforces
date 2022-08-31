#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(m);
	for(int i = 0; i < m; i++){
		cin >> a[i];
		a[i] -= 1;
	}
	ll ans = 0;
	int cur = 0;
	while(cur < m){
		ll v = cur;
		ll g = (a[cur] - v)/ k;
		while(cur < m && (a[cur] - v) / k == g){
			cur += 1;
		}
		ans += 1;
	}
	cout << ans << '\n';
}