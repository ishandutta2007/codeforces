#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int stuff[n][n];
	int dp[2][n][n];
	int dir[2][n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &stuff[n-1-i][n-1-j]);
		}
	}
	if(stuff[0][0] == 0 || stuff[n-1][n-1] == 0){
		cout << 1 << endl;
		for(int i = 0; i < n-1; i++){
			cout << "DR";
		}
		cout << endl;
		return 0;
	}
	int zerox = -1;
	int zeroy = -1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(stuff[i][j] == 0){
				zerox = i;
				zeroy = j;
				dp[0][i][j] = 10000000;
				dp[1][i][j] = 10000000;
			} else {
				dp[0][i][j] = 0;
				dp[1][i][j] = 0;
				while(stuff[i][j] % 2 == 0){
					dp[0][i][j]++;
					stuff[i][j] /= 2;
				}
				while(stuff[i][j] % 5 == 0){
					dp[1][i][j]++;
					stuff[i][j] /= 5;
				}
				if(i == 0 && j == 0){

				} else if(i == 0){
					for(int z = 0; z < 2; z++){
						dir[z][i][j] = 2;
						dp[z][i][j] += dp[z][i][j-1];
					}
				} else if(j == 0){
					for(int z = 0; z < 2; z++){
						dir[z][i][j] = 1;
						dp[z][i][j] += dp[z][i-1][j];
					}
				} else {
					for(int z = 0; z < 2; z++){
						if(dp[z][i-1][j] <= dp[z][i][j-1]){
							dp[z][i][j] += dp[z][i-1][j];
							dir[z][i][j] = 1;
						} else {
							dp[z][i][j] += dp[z][i][j-1];
							dir[z][i][j] = 2;
						}
					}
				}
			}
		}
	}
	if(zerox >= 0 && dp[0][n-1][n-1] > 0 && dp[1][n-1][n-1] > 0){
		cout << 1 << endl;
		for(int i = zeroy; i < n-1; i++){
			cout << "R";
		}
		for(int i = zerox; i < n-1; i++){
			cout << "D";
		}
		for(int i = 0; i < zeroy; i++){
			cout << "R";
		}
		for(int i = 0; i < zerox; i++){
			cout << "D";
		}
		cout << endl;
		return 0;
	}
	int minc = 0;
	if(dp[1][n-1][n-1] < dp[0][n-1][n-1]){
		minc = 1;
	}
	cout << min(dp[1][n-1][n-1], dp[0][n-1][n-1]) << endl;
	int cx = n-1;
	int cy = n-1;
	while(cx + cy > 0){
		if(dir[minc][cx][cy] == 1){
			cout << "D";
			cx--;
		} else {
			cout << "R";
			cy--;
		}
	}
	cout << endl;
}