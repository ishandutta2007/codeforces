#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<vector<int> > a(2, vector<int>(n));
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			a[i][j]++;
		}
	}
	a[0][0] = 0;
	vector<vector<int> > neg(2, vector<int>(n));
	vector<vector<int> > pos(2, vector<int>(n));
	for(int z = 0; z < 2; z++){
		vector<int>& p0 = neg[z];
		vector<int>& p1 = pos[z];
		for(int i = 0; i < n; i++){
			p0[i] = a[z][i] - (n-1-i);
			p1[i] = a[z][i] + (n-1-i);
		}
		for(int i = n-1; i > 0; i--){
			p0[i-1] = max(p0[i-1], p0[i]);
			p1[i-1] = max(p1[i-1], p1[i]);
		}
	}

	int ans = 2e9;
	int cmax = 0;
	for(int i = 0; i < n; i++){
		int s = i & 1;
		ans = min(ans, max({cmax, pos[s][i] - (2 * i + n-1-i), neg[s^1][i] - (2 * i + n-1-i + 1)}));
		cmax = max({cmax, a[s][i] - 2 * i, a[s^1][i] - 2 * i - 1});
	}
	cout << (ans + (2 * n-1)) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}