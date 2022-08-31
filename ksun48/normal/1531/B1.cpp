#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<tuple<int,int> > a(n);
	for(auto& [x, y] : a) cin >> x >> y;
	map<int,int> freq;
	long long ans = 0	;
	map<pair<int,int>, int> pair_freq;
	for(auto [x, y] : a){
		if(x > y) swap(x, y);
		if(x != y){
			ans += freq[x];
			ans += freq[y];
			ans -= pair_freq[{x, y}];
			freq[x]++;
			freq[y]++;
			pair_freq[{x, y}]++;
		} else {
			ans += freq[x];
			freq[x]++;
		}
	}
	cout << ans << '\n';
}