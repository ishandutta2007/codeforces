#include <iostream>
#include <vector>
#define mod 1000000007

using namespace std;

int N;
char code[5005];
int dp[5005][5005];
vector<int> vec;

int main(void)
{
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> code[i];
	
	int cnt = 0;
	for(int i = 1; i <= N-1; i++){
		if(code[i] == 'f') cnt++;
		if(code[i] == 's') vec.push_back(cnt);
	}
	
	dp[0][0] = 1;
	for(int i = 1; i <= vec.size(); i++){
		for(int j = 0; j <= N; j++){
			if(j > vec[i-1]) continue;
			if(j > 0) dp[i][j] = dp[i][j-1];
			dp[i][j] += dp[i-1][j];
			dp[i][j] %= mod;
		}
	}
	
	int ans = 0;
	for(int i = 0; i <= N; i++){
		ans += dp[vec.size()][i];
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}