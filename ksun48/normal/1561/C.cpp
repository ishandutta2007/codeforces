#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve(){
	int n;
	cin >> n;
	vector<pair<int,int> > z;
	for(int _ = 0; _ < n; _++){
		int k;
		cin >> k;
		int v = 0;
		for(int i = 0; i < k; i++){
			int x;
			cin >> x;
			v = max(x - i, v);
		}
		z.push_back({v+1, k});
	}
	sort(z.begin(), z.end());
	ll st = 0;
	ll gain = 0;
	for(auto [a, b] : z){
		if(st + gain < a){
			st = a - gain;
		}
		gain += b;
	}
	cout << st << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}