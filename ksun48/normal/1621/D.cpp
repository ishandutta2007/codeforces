#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve(){
	int n;
	cin >> n;
	vector<vector<ll> > a(2*n, vector<ll>(2*n, 0));
	for(int i = 0; i < 2*n; i++){
		for(int j = 0; j < 2*n; j++){
			cin >> a[i][j];
		}
	}
	vector<vector<ll> > b(n, vector<ll>(n));
	ll ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ans += a[i][j] + a[i+n][j+n];
		}
	}
	ll v = 2e18;
	v = min(v, a[0][n]);
	v = min(v, a[0][n+n-1]);
	v = min(v, a[n-1][n]);
	v = min(v, a[n-1][n+n-1]);
	v = min(v, a[n+0][0]);
	v = min(v, a[n+0][n-1]);
	v = min(v, a[n+n-1][0]);
	v = min(v, a[n+n-1][n-1]);
	ans += v;
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}