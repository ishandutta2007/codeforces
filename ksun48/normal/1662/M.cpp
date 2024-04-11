#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	int maxr = 0, maxw = 0;
	for(int i = 0; i < m; i++){
		int r, w;
		cin >> r >> w;
		maxr = max(maxr, r);
		maxw = max(maxw, w);
	}
	if(maxr + maxw > n){
		cout << "IMPOSSIBLE" << '\n';
	} else {
		string ans = string(maxr, 'R') + string(n - maxr, 'W');
		cout << ans << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}