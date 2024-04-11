#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll num_paths(ll a, ll n){
	ll b = a;
	if(a % 2 == 0){
		b = a / 2;
	}
	ll res = 0;
	for(ll i = 0; ; i++){
		if((b << i) > n) break;
		res += min(n, ((b + 1) << i) - 1) - (b << i) + 1;
	}
	if(a % 2 == 0) res--;
	return res;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, k;
	cin >> n >> k;
	ll best = 1;
	{
		ll s = 0;
		ll e = n / 2 + 1;
		while(s + 1 < e){
			ll m = (s + e) / 2;
			if(num_paths(2 * m, n) >= k){
				s = m;
			} else {
				e = m;
			}
		}
		if(s > 0 && s * 2 <= n && num_paths(2 * s, n) >= k){
			best = max(best, 2*s);
		}
	}
	{
		ll s = 0;
		ll e = (n + 1) / 2;
		while(s + 1 < e){
			ll m = (s + e) / 2;
			if(num_paths(2 * m + 1, n) >= k){
				s = m;
			} else {
				e = m;
			}
		}
		if(s >= 0 && s * 2 + 1 <= n && num_paths(2 * s + 1, n) >= k){
			best = max(best, 2*s + 1);
		}

	}
	cout << best << '\n';
}