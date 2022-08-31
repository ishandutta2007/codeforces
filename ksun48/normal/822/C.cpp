#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;
	ll n, x;
	cin >> n >> x;
	vector<ll> l(n), r(n), cost(n);
	for(int i = 0; i < n; i++){
		cin >> l[i] >> r[i] >> cost[i];
	}
	vector<ll> lord(n);
	vector<ll> rord(n);
	for(int i = 0; i < n; i++) lord[i] = rord[i] = i;
	sort(lord.begin(), lord.end(), [&](int a, int b){ return l[a] < l[b]; });
	sort(rord.begin(), rord.end(), [&](int a, int b){ return r[a] < r[b]; });
	ll best = 1e18;

	ll rc = 0;

	map<ll, ll> best_cost;

	for(int lc = 0; lc < n; lc++){
		while(rc < n && r[rord[rc]] < l[lord[lc]]){
			ll dur = r[rord[rc]] - l[rord[rc]] + 1;
			if(best_cost.count(dur)){
				best_cost[dur] = min(best_cost[dur], cost[rord[rc]]);
			} else {
				best_cost[dur] = cost[rord[rc]];
			}
			rc++;
		}
		ll need = x - (r[lord[lc]] - l[lord[lc]] + 1);
		if(best_cost.count(need)){
			best = min(best, best_cost[need] + cost[lord[lc]]);
		}
	}
	if(best >= ll(1e18)) best = -1;
	cout << best << '\n';
}