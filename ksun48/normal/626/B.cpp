#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int dp[3][210][210][210];
int main(){
	int n;
	cin >> n;
	string r;
	cin >> r;
	int zk[3];
	string a1 = "BGR";
	zk[0] = zk[1] = zk[2] = 0;
	for(int i = 0; i < n; i++){
		if(r[i] == 'B'){
			zk[0]++;
		} else if(r[i] == 'G'){
			zk[1]++;
		} else if(r[i] == 'R'){
			zk[2]++;
		}
	}
	//cout << zk[0] << zk[1] << zk[2]<< endl;
	for(int i = 0; i < 3; i++){
	for(int j = 0; j < 210; j++){
	for(int k = 0; k < 210; k++){
	for(int l = 0; l < 210; l++){
		dp[i][j][k][l] = 0;
		}
	}
	}
	}
	dp[0][1][0][0] = 1;
	dp[1][0][1][0] = 1;
	dp[2][0][0][1] = 1;
	for(int c = 0; c < 3; c++){
		for(int s = 2; s <= 600; s++){
			for(int i = 0; i <= s && i <= 200; i++){
				for(int j = 0; (i+j) <= s && j <= 200; j++){
					int k = s-i-j;
					if(k > 200) continue;
					if(i >= 2){
						dp[c][i][j][k] |= dp[c][i-1][j][k];
					}
					if(j >= 2){
						dp[c][i][j][k] |= dp[c][i][j-1][k];
					}
					if(k >= 2){
						dp[c][i][j][k] |= dp[c][i][j][k-1];
					}
					if(i >= 1 && j >= 1){
						dp[c][i][j][k] |= dp[c][i-1][j-1][k+1];
					}
					if(k >= 1 && j >= 1){
						dp[c][i][j][k] |= dp[c][i+1][j-1][k-1];
					}
					if(i >= 1 && k >= 1){
						dp[c][i][j][k] |= dp[c][i-1][j+1][k-1];
					}
					//if(i == 0 && j == 2 && k == 1) cout << dp[c][i][j][k] << " " << c << " " << i << " " << j << " " << k << endl;
				}
			}
		}	
	}
		for(int c = 0; c < 3; c++){
		if(dp[c][zk[0]][zk[1]][zk[2]] == 1){
			cout << a1[c];
		}
	}
	cout << endl;
}