#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, X;
	cin >> n >> X;
	map<int, vector<int>> a;
	for(int i = 0; i < n; i++){
		int r;
		cin >> r;
		int c = 0;
		while(r % X == 0){
			r /= X;
			c ++;
		}
		a[r].push_back(c);
	}
	int pairs = 0;
	for(auto [f, l] : a){
		int m = 0;
		for(int x : l){
			m = max(m, x);
		}
		vector<int> g(m+1, 0);
		for(int x : l) g[x]++;
		for(int i = 0; i + 1 <= m; i++){
			int r = min(g[i], g[i+1]);
			g[i+1] -= r;
			g[i] -= r;
			pairs += r;
		}
	}
	cout << (n - 2 * pairs) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}