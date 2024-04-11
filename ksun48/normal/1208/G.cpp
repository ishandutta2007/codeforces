#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;

	vector<ll> phi(n+1, 0);
	for(int i = 0; i <= n; i++){
		phi[i] = i;
	}
	for(int i = 1; i <= n; i++){
		for(int d = i*2; d <= n; d += i){
			phi[d] -= phi[i];
		}
	}

	ll res = 1e18;

	if(k <= (n - 1) / 2){
		// odds only
		vector<ll> z;
		for(int p = 3; p <= n; p += 2){
			z.push_back(phi[p]);
		}
		sort(z.begin(), z.end());
		ll ans = 1;
		for(int i = 0; i < k; i++){
			ans += z[i];
		}
		res = min(res, ans);
	}
	{
		vector<ll> z;
		for(int p = 3; p <= n; p += 1){
			z.push_back(phi[p]);
		}
		sort(z.begin(), z.end());
		ll ans = 2;
		for(int i = 0; i < k; i++){
			ans += z[i];
		}
		res = min(res, ans);
	}
	cout << res << '\n';
}