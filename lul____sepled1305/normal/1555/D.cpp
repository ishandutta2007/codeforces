#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m; cin>>n>>m;
	string s; cin>>s;
	//only 6 possibilities
	//Pre-process the string
	int dp[n+1][6];
	dp[0][0] = 0; //abc
	dp[0][1] = 0; //acb
	dp[0][2] = 0; //bac
	dp[0][3] = 0; //bca
	dp[0][4] = 0; //cab
	dp[0][5] = 0; //cba
	for(int i=0;i<n;i++) {
		for(int j=0;j<6;j++) {
			dp[i+1][j] = dp[i][j];
			//cout<<dp[i][j]<<' ';
		}
		//cout<<endl;
		if(s[i] == 'a') {
			if(i%3 == 0) {
				dp[i+1][0]++;
				dp[i+1][1]++;
			}
			else if(i%3 == 1) {
				dp[i+1][2]++;
				dp[i+1][4]++;
			}
			else {
				dp[i+1][3]++;
				dp[i+1][5]++;
			}
		}
		else if(s[i] == 'b') {
			if(i%3 == 0) {
				dp[i+1][2]++;
				dp[i+1][3]++;
			}
			else if(i%3 == 1) {
				dp[i+1][0]++;
				dp[i+1][5]++;
			}
			else {
				dp[i+1][1]++;
				dp[i+1][4]++;
			}
		}
		else {
			if(i%3 == 0) {
				dp[i+1][4]++;
				dp[i+1][5]++;
			}
			else if(i%3 == 1) {
				dp[i+1][1]++;
				dp[i+1][3]++;
			}
			else {
				dp[i+1][0]++;
				dp[i+1][2]++;
			}
		}
	}
	for(int i=0;i<m;i++) {
		int l,r;
		cin>>l>>r; l--,r--;
		int mini = 0;
		for(int j=0;j<6;j++) {
			mini = max(mini,dp[r+1][j]-dp[l][j]);
		}
		cout<<(r-l+1)-mini<<endl;
	}
	return 0;
}