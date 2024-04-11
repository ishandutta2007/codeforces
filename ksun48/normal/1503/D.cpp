#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<int> > a(n, vector<int>(2));
	vector<int> sw(n);
	for(int i = 0; i < n; i++){
		cin >> a[i][0] >> a[i][1];
		sw[i] = (a[i][0] > a[i][1]);
		sort(a[i].begin(), a[i].end());
	}
	vector<int> xord(n);
	set<pair<int,int> > xs, ys;
	for(int i = 0; i < n; i++){
		xs.insert({a[i][0], i});
		ys.insert({a[i][1], i});
	}
	vector<pair<int,int> > used;
	int ans = 0;
	while(!xs.empty()){
		auto [_, i] = *xs.begin();
		int tot = 0;
		int nsw = 0;
		xs.erase({a[i][0], i});
		ys.erase({a[i][1], i});
		used.push_back({a[i][0], a[i][1]});
		tot++;
		nsw += sw[i];
		int ly = a[i][1];
		int tx = 0;
		while(!xs.empty()){
			{
				auto [y, j] = *prev(ys.end());
				if(y > ly){
					tx = max(tx, a[j][0]);
					xs.erase({a[j][0], j});
					ys.erase({a[j][1], j});
					tot++;
					nsw += (1 ^ sw[j]);
					used.push_back({a[j][1], a[j][0]});
					continue;
				}
			}
			{
				auto [x, j] = *xs.begin();
				if(x < tx){
					ly = min(ly, a[j][1]);
					xs.erase({a[j][0], j});
					ys.erase({a[j][1], j});
					tot++;
					nsw += sw[j];
					used.push_back({a[j][0], a[j][1]});
					continue;
				}
			}
			break;
		}
		ans += min(nsw, tot - nsw);
	}
	sort(used.begin(), used.end());
	for(int i = 0; i + 1 < n; i++){
		if(used[i].first < used[i+1].first && used[i].second > used[i+1].second) continue;
		cout << -1 << '\n';
		return 0;
	}
	cout << ans << '\n';
}