#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	int s = n-1 + m-1;
	vector<vector<int> > freqs(n + m, vector<int>(2, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int a;
			cin >> a;
			if(i + j == (s - i - j)) continue;
			int r = min(i + j, s - i - j);
			freqs[r][a]++;
		}
	}
	int ans = 0;
	for(vector<int> z : freqs){
		ans += min(z[0], z[1]);
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}