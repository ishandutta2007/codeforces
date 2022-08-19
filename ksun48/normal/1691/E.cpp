#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<map<int, int> > diffs(2);
	vector<tuple<int, int, int> > segs;
	vector<int> x;
	for(int i = 0; i < n; i++){
		int c;
		cin >> c;
		int l, r;
		cin >> l >> r;
		r++;
		diffs[c][l]++;
		diffs[c][r]--;
		x.push_back(l);
		x.push_back(r);
		segs.push_back({c, l, r});
	}
	sort(x.begin(), x.end());
	x.resize(unique(x.begin(), x.end()) - x.begin());
	vector<int> cnt(2, 0);
	vector<int> both_locs;
	for(int a : x){
		cnt[0] += diffs[0][a];
		cnt[1] += diffs[1][a];
		if(cnt[0] && cnt[1]){
			both_locs.push_back(a);
		}
	}
	vector<pair<int,int> > ivals;
	int ccs = 0;
	for(auto [c, l, r] : segs){
		auto f = lower_bound(both_locs.begin(), both_locs.end(), l);
		if(f == both_locs.end() || *f >= r){
			ccs++;
		} else {
			int g = f - both_locs.begin();
			int h = prev(lower_bound(both_locs.begin(), both_locs.end(), r)) - both_locs.begin();
			assert(g <= h);
			ivals.push_back({g, h});
		}
	}
	ccs += (int)both_locs.size();
	if(!both_locs.empty()){
		int k = (int)both_locs.size();
		vector<int> d(k, 0);
		for(auto [a, b] : ivals){
			if(a < b){
				// a -> b-1
				d[a] += 1;
				d[b] -= 1;
			}
		}
		int y = 0;
		for(int z : d){
			y += z;
			if(y > 0) ccs--;
		}
	}
	cout << ccs << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}