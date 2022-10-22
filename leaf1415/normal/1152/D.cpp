#include <iostream>
#define llint long long
#define mod 1000000007

using namespace std;

llint n;
llint dp[1005][1005];
bool used[1005][1005];

int main(void)
{
	cin >> n;
	
	for(int i = n+1; i >= 0; i--){
		for(int j = n+1; j >= 0; j--){
			dp[i][j] = 0;
			used[i][j] = true;
		}
	}
	for(int i = n; i >= 0; i--){
		for(int j = n; j >= 0; j--){
			if(i > j) continue;
			dp[i][j] = dp[i+1][j] + dp[i][j+1];
			if(!used[i+1][j] || !used[i][j+1]) dp[i][j] += 1, used[i][j] = true;
			else used[i][j] = false;
			dp[i][j] %= mod;
		}
	}
	/*for(int i = n+1; i >= 0; i--){
		for(int j = 0; j <= n+1; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	
	cout << dp[0][0] << endl;
	
	return 0;
}