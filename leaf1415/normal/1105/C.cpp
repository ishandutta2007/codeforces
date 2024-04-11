#include <iostream>
#define llint long long
#define mod 1000000007

using namespace std;

llint n, l, r;
llint num[3];
llint dp[200005][3];

llint get(llint l, llint r)
{
	return r/3-(l-1)/3;
}

int main(void)
{
	cin >> n >> l >> r;
	
	num[0] = get(l, r);
	num[1] = get(l+2, r+2);
	num[2] = get(l+1, r+1);
	
	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				dp[i+1][(j+k)%3] += dp[i][j] * num[k] % mod;
				dp[i+1][(j+k)%3] %= mod;
			}
		}
	}
	cout << dp[n][0] << endl;
	
	return 0;
}