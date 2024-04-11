#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	int maxv = 0;
	int minv = 1e9;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		maxv = max(maxv, a[i]);
		minv = min(minv, a[i]);
	}
	if(minv * 2 >= maxv){
		for(int i = 0; i < n; i++){
			cout << -1 << ' ';
		}
		cout << '\n';
		return 0;
	}
	vector<pair<int,int> > a_sorted;
	for(int i = 0; i < n; i++){
		a_sorted.push_back({a[i], i});
	}
	sort(a_sorted.begin(), a_sorted.end());
	set<int> bad_music;
	vector<int> ans(n, 3 * n + 1);
	int f = 0;
	for(int i = 0; i < n; i++){
		int idx = a_sorted[i].second;
		while(f < n && a_sorted[f].first * 2 < a_sorted[i].first){
			bad_music.insert(a_sorted[f].second);
			f++;
		}
		if(!bad_music.empty()){
			if(bad_music.lower_bound(idx) != bad_music.end()){
				ans[idx] = *bad_music.lower_bound(idx) - idx;
			} else {
				ans[idx] = n + *bad_music.begin() - idx;
			}
		}
	}

	for(int j = 0; j < 3; j++) for(int i = n-1; i >= 0; i--){
		ans[i] = min(ans[(i+1) % n] + 1, ans[i]);
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';
}