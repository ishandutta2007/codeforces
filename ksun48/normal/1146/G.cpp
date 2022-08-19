#include <bits/stdc++.h>
using namespace std;

int dp[52][52][52];

vector<vector<int> > l(52);
vector<vector<int> > r(52);
vector<vector<int> > c(52);
int main(){
	int n, h, m;
	cin >> n >> h >> m;
	int csum = 0;
	for(int i = 0; i < m; i++){
		int L, R, X, C;
		cin >> L >> R >> X >> C;
		L--; R--;
		l[X].push_back(L);
		r[X].push_back(R);
		c[X].push_back(C);
		csum -= C;
	}
	for(int f = 0; f <= h; f++){
		for(int i = 0; i < n; i++){
			for(int j = i; j <= n; j++){
				if(j > i){
					dp[f][i][j] = max(dp[f][i][j], dp[f][i][j-1] + f * f);
				}
				if(f > 0){
					for(int k = i; k < j; k++){
						dp[f][i][j] = max(dp[f][i][j], dp[f][i][k] + dp[f-1][k][j]);
					}
				}
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = i; j <= n; j++){
				int b = l[f].size();
				for(int a = 0; a < b; a++){
					if(i <= l[f][a] && r[f][a] < j){
						dp[f][i][j] += c[f][a];
					}
				}
			}
		}
	}
	cout << csum + dp[h][0][n] << '\n';
}