#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> p(n);
	for(int& x : p) cin >> x;
	vector<vector<int> > l(n, vector<int>(n, 0)), r(n, vector<int>(n, 0));
	for(int b = 0; b < n; b++){
		int cnt = 0;
		for(int c = n-1; c > b; c--){
			l[b][c] = cnt;
			cnt += p[c] < p[b];
		}
	}
	for(int c = 0; c < n; c++){
		int cnt = 0;
		for(int b = 0; b < c; b++){
			r[b][c] = cnt;
			cnt += p[b] < p[c];
		}
	}
	using ll = int64_t;
	ll ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ans += ll(l[i][j]) * ll(r[i][j]);
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