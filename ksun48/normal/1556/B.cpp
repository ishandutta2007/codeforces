#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a){
		cin >> x;
		x = x & 1;
	}
	ll M = 1e13;
	ll ans = M;
	for(int j = 0; j < 2; j++){
		vector<int> b(n);
		for(int i = 0; i < n; i++){
			b[i] = (i & 1) == j;
		}
		vector<int> la, lb;
		for(int i = 0; i < n; i++){
			if(a[i]) la.push_back(i);
			if(b[i]) lb.push_back(i);
		}
		if(la.size() != lb.size()) continue;
		ll ops = 0;
		for(int i = 0; i < (int)la.size(); i++){
			ops += abs(la[i] - lb[i]);
		}
		ans = min(ans, ops);
	}
	if(ans >= M) ans = -1;
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}