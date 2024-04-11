#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> r(n);
	vector<int> freq(n, 0);
	for(int i = 0; i < n; i++){
		cin >> r[i];
		r[i]--;
		freq[r[i]]++;
	}
	int best = 0;
	int nc = 0;
	for(int i = 0; i < n; i++){
		if(freq[i] > freq[best]){
			best = i;
			nc = 1;
		} else if(freq[i] == freq[best]){
			nc++;
		}
	}
	if(nc > 1){
		cout << n << '\n';
		return 0;
	}
	set<int> l0;
	vector<vector<int> > where(n);
	for(int i = 0; i < n; i++){
		if(r[i] == best){
			l0.insert(i);
		} else {
			where[r[i]].push_back(i);
		}
	}

	vector<int> z(2*n+3, -1);
	int ans = 0;
	for(int i = 0; i < n; i++){
		vector<int> locs = where[i];
		vector<int> care0;
		for(int a : locs){
			for(int j = 0; j < 2; j++){
				auto f = l0.lower_bound(a);
				if(f != l0.end()){
					care0.push_back(*f);
					l0.erase(f);
				}
			}
			for(int j = 0; j < 2; j++){
				auto f = l0.lower_bound(a);
				if(f != l0.begin()){
					f = prev(f);
					care0.push_back(*f);
					l0.erase(f);
				}
			}
		}
		vector<pair<int,int> > events;
		for(int a : care0) events.push_back({a, 1});
		events.push_back({n, 1});
		for(int a : locs) events.push_back({a, -1});
		sort(events.begin(), events.end());
		int prev = 0;
		int csum = n+1;
		int maxcsum = n+1;
		int mincsum = n+1;
		for(pair<int,int> p : events){
			if(z[csum] >= 0){
				ans = max(ans, p.first - z[csum]);
			} else {
				z[csum] = prev;
				maxcsum = max(maxcsum, csum);
				mincsum = min(mincsum, csum);
			}
			prev = p.first + 1;
			csum += p.second;
		}
		for(int g = mincsum; g <= maxcsum; g++) z[g] = -1;
		for(int a : care0) l0.insert(a);
	}
	cout << ans << '\n';
}