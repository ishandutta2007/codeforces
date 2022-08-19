#include <bits/stdc++.h>
using namespace std;

void solve(){
	int ans = 0;
	int n;
	cin >> n;
	vector<vector<int> > a(n, vector<int>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	for(int x = 0; x <= 2*n-1; x += 4){
		int minv = max(0, x - (n-1));
		int maxv = min(x, n-1);
		for(int j = minv; j <= maxv; j += 2){
			ans ^= a[j][x-j];
			ans ^= a[j][n-1-(x-j)];
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