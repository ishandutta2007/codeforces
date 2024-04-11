#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<vector<int> > a(2);
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		a[v & 1].push_back(v);
	}
	for(vector<int> x : a){
		vector<int> sx = x;
		sort(sx.begin(), sx.end());
		if(sx != x){
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}