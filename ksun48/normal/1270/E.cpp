#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	using ll = long long;
	int n;
	cin >> n;
	vector<pair<ll,ll> > c(n);
	for(int i = 0; i < n; i++){
		cin >> c[i].first >> c[i].second;
	}
	while(true){
		vector<int> groups[2];
		for(int i = 0; i < n; i++){
			groups[(c[i].first + c[i].second) & 1].push_back(i);
		}
		if(groups[0].empty() || groups[1].empty()){
			for(int i = 0; i < n; i++){
				if((c[i].first + c[i].second) & 1) c[i].second -= 1;
				ll a = (c[i].first + c[i].second) / 2;
				ll b = (c[i].first - c[i].second) / 2;
				c[i] = {a, b};
			}
		} else {
			cout << groups[0].size() << '\n';
			for(int a : groups[0]){
				cout << a + 1 << ' ';
			}
			cout << '\n';
			exit(0);
		}
	}
}