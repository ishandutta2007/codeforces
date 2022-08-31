#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int> > dj(n, vector<int>(m-1));
	for(vector<int>& x : dj) for(int& y : x) cin >> y;
	vector<vector<int> > di(n-1, vector<int>(m));
	for(vector<int>& x : di) for(int& y : x) cin >> y;
	vector<vector<int> > ans(n, vector<int>(m, 0));
	if(k & 1){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				ans[i][j] = -1;
			}
		}
	} else {
		for(int z = 0; z < k; z += 2){
			vector<vector<int> > na(n, vector<int>(m, 1e9));
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					if(j+1 < m){
						na[i][j] = min(na[i][j], ans[i][j+1] + dj[i][j]);
						na[i][j+1] = min(na[i][j+1], ans[i][j] + dj[i][j]);						
					}
					if(i+1 < n){
						na[i][j] = min(na[i][j], ans[i+1][j] + di[i][j]);
						na[i+1][j] = min(na[i+1][j], ans[i][j] + di[i][j]);
					}
				}
			}
			ans = na;
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				ans[i][j] *= 2;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}