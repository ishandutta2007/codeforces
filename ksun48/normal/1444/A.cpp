#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve(){
	ll p, q;
	cin >> p >> q;
	ll best = 0;
	set<ll> pf;
	ll cq = q;
	for(ll r = 2; r * r <= cq; r++){
		while(cq % r == 0){
			pf.insert(r);
			cq /= r;
		}
	}
	if(cq > 1) pf.insert(cq);
	for(ll r : pf){
		ll cp = p;
		while(cp % q == 0) cp /= r;
		best = max(best, cp);
	}
	cout << best << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}