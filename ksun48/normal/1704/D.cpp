#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
void solve(){
	int n, m;
	cin >> n >> m;
	vector<ll> sums(n, 0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			ll a;
			cin >> a;
			sums[i] += ll(j) * ll(a);
		}
	}
	int r = 0;
	for(int i = 0; i < n; i++) if(sums[i] > sums[r]) r = i;
	cout << (r+1) << ' ' << (sums[r] - min(sums[0], sums[1])) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}