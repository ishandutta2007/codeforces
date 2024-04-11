#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n, vector<int>(m));
	for(vector<int>& x : a) for(int& y : x) cin >> y;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int r = 4;
			if(i == 0 || i == n-1) r--;
			if(j == 0 || j == m-1) r--;
			if(a[i][j] > r){
				cout << "NO" << '\n';
				return;
			}
			a[i][j] = r;
		}
	}
	cout << "YES" << '\n';
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}