#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<pair<ll, int> > pos(n);
	vector<ll> target(n);
	for(int i = 0; i < n; i++){
		cin >> pos[i].first;
		pos[i].second = i;
	}
	for(int i = 0; i < n; i++) cin >> target[i];
	sort(pos.begin(), pos.end());
	sort(target.begin(), target.end());
	ll s1 = 0, s2 = 0;
	for(int i = 0; i < n; i++){
		s1 += pos[i].first;
		s2 += target[i];
		if(s1 > s2){
			cout << "NO" << '\n';
			exit(0);
		}
	}
	if(s1 != s2){
		cout << "NO" << '\n';
		exit(0);
	}
	vector<int> si, sj;
	vector<ll> d;
	map<pair<ll, int>, ll> diffs;
	for(int i = 0; i < n; i++){
		if(pos[i].first != target[i]){
			diffs[pos[i]] = target[i] - pos[i].first;
		}
	}
	set<pair<ll, int> > locations;
	for(auto it = diffs.begin(); it != diffs.end(); it++){
		if(next(it) == diffs.end()) continue;
		if(it->second > 0 && next(it)->second < 0){
			locations.insert(it->first);
		}
	}
	while(!locations.empty()){
		pair<ll, int> v = *locations.begin();
		locations.erase(v);
		auto it1 = diffs.find(v);
		if(it1 == diffs.end()) continue;
		if(next(it1) == diffs.end()) continue;

		auto it2 = next(it1);
		pair<ll, int> a = it1->first;
		pair<ll, int> b = it2->first;

		ll ac = it1->second;
		ll bc = it2->second;
		if(ac < 0 || bc > 0) continue;
		assert(ac > 0 && bc < 0);

		diffs.erase(a);
		diffs.erase(b);
		ll c = min(ac, -bc);
		ac -= c;
		bc += c;
		a.first += c;
		b.first -= c;
		si.push_back(a.second);
		sj.push_back(b.second);
		d.push_back(c);
		if(ac != 0){
			diffs[a] = ac;
			auto it = next(diffs.find(a));
			if(it != diffs.end() && it->second < 0){
				locations.insert(a);
			}
		} else if(bc != 0){
			diffs[b] = bc;
			auto it = diffs.find(b);
			if(it != diffs.begin() && prev(it)->second > 0){
				locations.insert(prev(it)->first);
			}
		} else {
			auto r = diffs.lower_bound(b);
			if(r != diffs.begin() && r != diffs.end()){
				auto s = prev(r);
				if(r->second < 0 && s->second > 0){
					locations.insert(s->first);
				}
			}
		}
	}
	assert(diffs.empty());
	cout << "YES" << '\n';
	cout << d.size() << '\n';
	for(int i = 0; i < (int)d.size(); i++){
		cout << si[i] + 1 << ' ' << sj[i] + 1 << ' ' << d[i] << '\n';
	}
}