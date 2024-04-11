#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a, b;

ll best[5000000];

ll get(ll x);

ll compute(ll x){
	if(x == 0) return 0;
	if(x - a >= 0) return max(x, get(x-a));
	return get(x+b);
}

ll get(ll x){
	if(best[x] == -1){
		best[x] = compute(x);
	}
	return best[x];
}

ll cnt(ll V, ll m, ll g){
	if(V < 0) return 0;
	ll num = V / g + 1;
	return (m+1) * num - g * num * (num - 1) / 2;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll m;
	cin >> m >> a >> b;
	ll g = __gcd(a, b);
	ll K = 2 * (a+b);
	for(int i = 0; i < K; i++){
		best[i] = -1;
	}
	for(int i = 0; i < K; i++){
		if(i % g == 0){
			get(i);
		}
	}
	ll ans = 0;
	for(int i = 0; i < K; i++){
		if(best[i] == -1) continue;
		ll v = best[i];
		if(v <= m){
			ans += (m - v + 1);
		}
	}
	ll diff = (m/g)*g - K;
	if(diff >= 0){
		ans += cnt(m, m, g) - cnt(K-1, m, g);
	}
	cout << ans << '\n';
}