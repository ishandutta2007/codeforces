#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, k, r[505][505], c[505][505], v[22][505][505];

void solve(){
	cin >> n >> m >> k;

	if(k % 2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) cout << "-1 ";
			cout << '\n';
		}
		return;
	}

	for(int i=1;i<=n;i++) for(int j=1;j<m;j++) cin >> r[i][j];
	for(int i=1;i<n;i++) for(int j=1;j<=m;j++) cin >> c[i][j];

	for(int b=2;b<=k;b+=2) for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		v[b][i][j] = 1e9;

		if(i > 1) v[b][i][j] = min(v[b][i][j], v[b-2][i-1][j] + c[i-1][j] * 2);
		if(i < n) v[b][i][j] = min(v[b][i][j], v[b-2][i+1][j] + c[i][j] * 2);

		if(j > 1) v[b][i][j] = min(v[b][i][j], v[b-2][i][j-1] + r[i][j-1] * 2);
		if(j < m) v[b][i][j] = min(v[b][i][j], v[b-2][i][j+1] + r[i][j] * 2);
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cout << v[k][i][j] << " ";
		cout << '\n';
	}

}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int tc = 1; // cin >> tc;
	while(tc--) solve();
}