#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for(string& x : s) cin >> x;
	int rx = -1, ry = -1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(s[i][j] == 'E') continue;
			if(rx == -1){
				rx = i;
				ry = j;
			}
			if(i < rx || j < ry){
				cout << "NO" << '\n';
				return;
			}
		}
	}
	cout << "YES" << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}