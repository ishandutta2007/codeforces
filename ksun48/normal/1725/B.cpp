#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	ll N, D;
	cin >> N >> D;
	vector<ll> P(N);
	for(ll& x : P) cin >> x;
	sort(P.rbegin(), P.rend());
	ll players = N;
	int ans = 0;
	for(ll x : P){
		ll need = D / x + 1;
		if(players >= need){
			players -= need;
			ans++;
		}
	}
	cout << ans << '\n';
}