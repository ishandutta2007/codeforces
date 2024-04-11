#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	string s;
	cin >> s;
	int n = (int)s.size();
	ll INF = ll(1e13);
	vector<ll> a(n), b(n);
	for(int i = 0; i < n; i++){
		if(s[i] == '('){
			a[i] = 0;
			b[i] = INF;
		} else if(s[i] == ')'){
			a[i] = INF;
			b[i] = 0;
		} else {
			cin >> a[i] >> b[i];
		}
	}
	string state(n, '?');
	vector<ll> edit_cost(n);
	ll base_cost = 0;
	for(int i = 0; i < n; i++){
		if(a[i] <= b[i]){
			state[i] = '(';
			base_cost += a[i];
			edit_cost[i] = b[i] - a[i];
		} else {
			state[i] = ')';
			base_cost += b[i];
			edit_cost[i] = a[i] - b[i];
		}
	}
	ll cost = base_cost;
	{
		set<pair<ll, int> > costs;
		int csum = 0;
		for(int i = 0; i < n; i++){
			if(state[i] == '('){
				csum++;
			} else {
				csum--;
				costs.insert({edit_cost[i], i});
			}
			if(csum < 0){
				auto [v, idx] = *costs.begin();
				state[idx] = '(';
				cost += v;
				costs.erase(costs.begin());
				csum += 2;
			}
		}
	}
	{
		set<pair<ll, int> > costs;
		int csum = 0;
		for(int i = n-1; i >= 0; i--){
			if(state[i] == ')'){
				csum++;
			} else {
				csum--;
				costs.insert({edit_cost[i], i});
			}
			if(csum < 0){
				auto [v, idx] = *costs.begin();
				state[idx] = ')';
				cost += v;
				costs.erase(costs.begin());
				csum += 2;
			}
		}
	}
	if(cost >= INF){
		cout << -1 << '\n';
	} else {
		cout << cost << '\n';
		cout << state << '\n';
	}
}