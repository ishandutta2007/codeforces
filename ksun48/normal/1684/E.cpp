#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	map<int, int> freq;
	for(int x : a) freq[x]++;
	vector<pair<int,int> > v;
	for(auto [x, f] : freq) v.push_back({x, f});
	int i = 0;
	while(i < (int)v.size() && v[i].first - i <= k){
		i++;
	}
	vector<int> bad;
	for(; i < (int)v.size(); i++){
		bad.push_back(v[i].second);
	}
	sort(bad.begin(), bad.end());
	int ans = (int)bad.size();
	for(int j = 0; j < bad.size(); j++){
		if(bad[j] <= k){
			k -= bad[j];
			ans--;
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