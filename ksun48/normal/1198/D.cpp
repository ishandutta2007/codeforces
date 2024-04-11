#include <bits/stdc++.h>
using namespace std;

int dp[52][52][52][52];

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<string> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int next_y[52][52];
	for(int i = n-1; i >= 0; i--){
		int cur = n;
		for(int j = n; j >= 0; j--){
			if(j < n){
				if(a[i][j] == '#'){
					cur = j;
				}
			}
			next_y[i][j] = cur;
		}
	}
	int next_x[52][52];
	for(int j = n-1; j >= 0; j--){
		int cur = n;
		for(int i = n; i >= 0; i--){
			if(i < n){
				if(a[i][j] == '#'){
					cur = i;
				}
			}
			next_x[i][j] = cur;
		}
	}
	for(int xa = 0; xa <= n; xa++){
		for(int xb = 0; xb <= n; xb++){
			for(int ya = 0; ya <= n; ya++){
				for(int yb = 0; yb <= n; yb++){
					dp[xa][xb][ya][yb] = 10000;
				}
			}
		}
	}
	for(int xa = n; xa >= 0; xa--){
		for(int xb = 0; xb <= n; xb++){
			for(int ya = n; ya >= 0; ya--){
				for(int yb = 0; yb <= n; yb++){
					if(xa >= xb || ya >= yb){
						dp[xa][xb][ya][yb] = 0;
						continue;
					}
					dp[xa][xb][ya][yb] = max(xb - xa, yb - ya);
					for(int xc = xa; xc < xb; xc++){
						if(next_y[xc][ya] < yb) continue;
						dp[xa][xb][ya][yb] = min(dp[xa][xb][ya][yb], dp[xa][xc][ya][yb] + dp[xc+1][xb][ya][yb]);
					}
					for(int yc = ya; yc < yb; yc++){
						if(next_x[xa][yc] < xb) continue;
						dp[xa][xb][ya][yb] = min(dp[xa][xb][ya][yb], dp[xa][xb][ya][yc] + dp[xa][xb][yc+1][yb]);
					}
				}
			}
		}
	}
	cout << dp[0][n][0][n] << '\n';
}