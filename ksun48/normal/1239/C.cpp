#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	ll p;
	cin >> p;
	vector<ll> t(n);
	for(int i = 0; i < n; i++) cin >> t[i];

	vector<pair<ll, int> > events;
	for(int i = 0; i < n; i++){
		events.push_back({t[i], i});
	}
	sort(events.begin(), events.end());
	vector<ll> ans(n);

	vector<int> wait_order;
	int s = 0;

	set<int> waiting_ids;
	waiting_ids.insert(n);
	set<int> waiting_to_wait;
	int cur = 0;
	ll start_water_time = 0;
	while(s < (int)wait_order.size() || cur < n){
		// 2 things that can happen: cur waits to wait, or somebody gets water (and people waiting to wait start waiting)
		int which = -1;
		if(cur == n){
			which = 0;
		} else if(s == (int)wait_order.size() ){
			which = 1;
		} else if(start_water_time + p < events[cur].first){
			which = 0;
		} else if(start_water_time + p >= events[cur].first){
			which = 1;
		} else assert(false);
		if(which == 0){
			// gets water
			start_water_time += p;
			int v = wait_order[s];
			ans[v] = start_water_time;
			//cerr << v << " gets water at " << start_water_time << '\n';
			waiting_ids.erase(v);
			s++;
		} else if(which == 1){
			if(s == (int)wait_order.size()){
				start_water_time = events[cur].first;
			}
			int v = events[cur].second;
			//cerr << v << " waits to wait at " << events[cur].first << '\n';
			waiting_to_wait.insert(v);
			cur++;
		}
		if(!waiting_to_wait.empty() && *waiting_to_wait.begin() < *waiting_ids.begin()){
			int v = *waiting_to_wait.begin();
			waiting_ids.insert(v);
			waiting_to_wait.erase(v);
			wait_order.push_back(v);
			//cerr << v << " gets in queue" << '\n';
		}
	}
	for(ll x : ans){
		cout << x << ' ';
	}
	cout << '\n';
}