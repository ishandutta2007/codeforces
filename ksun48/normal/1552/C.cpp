#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> done(2*n, 0);
	vector<pair<int,int> > v;
	for(int i = 0; i < k; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		if(a > b) swap(a, b);
		v.push_back({a, b});
		done[a] = done[b] = 1;
	}
	vector<int> z;
	for(int i = 0; i < 2*n; i++){
		if(!done[i]) z.push_back(i);
	}
	for(int j = 0; j < (int)z.size() / 2; j++){
		v.push_back({z[j], z[j+(int)z.size() / 2]});
	}
	int ans = 0;
	for(auto [l1, r1] : v){
		for(auto [l2, r2] : v){
			if(l1 < l2 && l2 < r1 && r1 < r2){
				ans++;
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