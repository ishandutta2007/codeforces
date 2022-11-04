#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[505][505], b[505];

void solve(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i][i], b[a[i][i]] = i;

	for(int i=1;i<n;i++){
		int u = b[i];

		// for(int j=1;j<=n-i;j++){
		// 	a[i+j][j] = -i;
		// }

		for(int j=1;j<u;j++){
			a[i+j][j] = a[i+j-1][j];
			// cout << "1 : " << i+j << " " << j << "\n";
		}
		for(int j=u;j<=n-i;j++){
			a[i+j][j] = a[i+j][j+1];
			// cout << "2 : " << i+j << " " << j << "\n";
		}
		// cout << "-----------\n";

		for(int j=1;j<=n-i;j++) b[a[i+j][j]] = j;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++) cout << a[i][j] << " ";
		cout << "\n";
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int tc = 1;
	while(tc--) solve();
}