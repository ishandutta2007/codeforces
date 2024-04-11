#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for(string& x : s) cin >> x;
	for(int z = 0; z < 2; z++){
		bool ok = true;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(s[i][j] == "RW"[(i + j + z) & 1]){
					ok = false;
				}
			}
		}
		if(ok){
			cout << "YES" << '\n';
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					cout << "RW"[(i + j + z + 1) & 1];
				}
				cout << '\n';
			}
			return;
		}
	}
	cout << "NO" << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}