#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	map<int, set<int> > aloc;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		aloc[a[i]].insert(i);
	}
	vector<pair<int,int> > segs(m);
	for(auto& [x, y] : segs){
		cin >> x >> y;
		x--; y--;
	}
	vector<int> seg_end(n), seg_start(n);
	for(int i = 0; i < n; i++) seg_end[i] = seg_start[i] = i;
	for(auto [l, r] : segs){
		seg_end[l] = max(seg_end[l], r);
		seg_start[r] = min(seg_start[r], l);
	}
	for(int i = 1; i < n; i++){
		seg_end[i] = max(seg_end[i], seg_end[i-1]);
	}
	for(int i = n-1; i > 0; i--){
		seg_start[i-1] = min(seg_start[i-1], seg_start[i]);
	}
	int ans = n;
	int maxcond = n-1;
	for(int i = n-1; i >= 0; i--){
		auto& s = aloc[a[i]];
		auto it = s.find(i);
		if(next(it) != s.end()){
			int nloc = *next(it);
			if(nloc <= seg_end[i]) break;
		}
		maxcond = i-1;
	}
	for(int i = 0; i < n; i++){
		ans = min(ans, max(0, (maxcond - i + 1)));
		auto& s = aloc[a[i]];
		{
			auto it = s.find(i);
			if(it != s.begin()){
				int ploc = (*prev(it));
				if(seg_start[i] <= ploc) break;
			}
		}
		auto it = s.upper_bound(seg_end[i]);
		if(it != s.begin()){
			int nloc = *prev(it);
			assert(nloc <= seg_end[i]);
			if(nloc > i){
				maxcond = max(maxcond, nloc);
			}
		}
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}