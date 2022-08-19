#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a){
		cin >> x;
		x--;
	}
	vector<int> last_occ(n, -1);
	vector<pair<int,int> > intervals;
	for(int i = 0; i < n; i++){
		int r = last_occ[a[i]];
		if(r >= 0){
			intervals.push_back({r, i});
		} else {
			last_occ[a[i]] = i;
		}
	}
	sort(intervals.begin(), intervals.end());
	vector<pair<int,int> > merged;
	vector<pair<int,int> > cmerged;
	int subtract = 0;
	auto calc = [&](){
		if(cmerged.empty()) return;
		auto [l, r] = merged.back();
		int b1 = 0;
		for(auto [x, y] : cmerged){
			if(x == l){
				b1 = max(b1, y);
			}
		}
		int cnt = 1;
		int cval = b1;
		int idx = 0;
		while(cval < r){
			int cand = cval;
			while(idx < cmerged.size() && cmerged[idx].first <= cval){
				cand = max(cand, cmerged[idx].second);
				idx++;
			}
			cnt++;
			cval = cand;
		}
		subtract -= (cnt - 1);
	};
	for(auto [x, y] : intervals){
		if(merged.empty() || x > merged.back().second){
			calc();
			cmerged = {};
			merged.push_back({x, y});
			cmerged.push_back({x, y});
		} else {
			merged.back().second = max(merged.back().second, y);
			cmerged.push_back({x, y});
		}
	}
	calc();
	int base_ans = 0;
	for(auto [x, y] : merged){
		base_ans += (y-x-1);
	}
	cout << (base_ans + subtract) << '\n';
}