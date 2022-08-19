#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	vector<pair<int,int>> r(n);
	for(auto& a : r) cin >> a.first >> a.second;
	for(auto p : r){
		int md = 0;
		for(auto q : r){
			md = max(md, abs(p.first - q.first) + abs(p.second - q.second));
		}
		if(md <= k){
			cout << 1 << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}