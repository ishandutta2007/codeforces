#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> str(n);
	for(int i = 0; i < n; i++){
		cin >> str[i];
	}
	vector<vector<bool> > dp0(n, vector<bool>(m, false));
	vector<vector<bool> > dp1(n, vector<bool>(m, false));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i == 0 && j == 0){
				dp0[i][j] = true;
			}
			if(str[i][j] == '#') continue;
			if(i > 0 && dp0[i-1][j]) dp0[i][j] = true;
			if(j > 0 && dp0[i][j-1]) dp0[i][j] = true;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i == 0 && j == 0){
				dp1[i][j] = true;
			}
			if(str[n-1-i][m-1-j] == '#') continue;
			if(i > 0 && dp1[i-1][j]) dp1[i][j] = true;
			if(j > 0 && dp1[i][j-1]) dp1[i][j] = true;
		}
	}
	vector<int> cnts(n+m, 0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(dp0[i][j] && dp1[n-1-i][m-1-j]){
				cnts[i+j] += 1;
			}
		}
	}
	int minv = 1e8;
	for(int b = 1; b <= n+m-3; b++){
		minv = min(minv, cnts[b]);
	}
	cout << minv << '\n';
	return 0;
}