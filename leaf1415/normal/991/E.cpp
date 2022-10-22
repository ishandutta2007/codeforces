#include <iostream>
#include <string>
#define llint long long

using namespace std;

string s;
llint cnt[10];
llint dp[25][25];

llint fact[105];

void make_fact()
{
	llint val = 1;
	fact[0] = 1;
	for(int i = 1; i < 105; i++){
		val *= i;
		fact[i] = val;
	}
}

llint comb(llint n, llint k)
{
	return fact[n] / fact[k] / fact[n-k];
}

llint calc(bool flag)
{
	for(int i = 0; i <= 10; i++){
		for(int j = 0; j <= 20; j++){
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	
	for(int i = 0; i < 10; i++){
		if(cnt[i] == 0){
			for(int j = 0; j <= 20; j++) dp[i+1][j] = dp[i][j];
			continue;
		}
		for(int j = 0; j <= 20; j++){
			if(flag && i == 0) dp[i+1][j] += dp[i][j];
			for(int k = 1; k <= cnt[i]; k++){
				dp[i+1][j+k] += comb(j+k, k) * dp[i][j];
			}
		}
	}
	
	/*for(int i = 0; i <= 10; i++){
		for(int j = 0; j <= 20; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	
	llint ret = 0;
	for(int i = 1; i <= 20; i++) ret += dp[10][i];
	return ret;
}

int main(void)
{
	make_fact();
	cin >> s;
	for(int i = 0; i < s.size(); i++) cnt[s[i]-'0']++;
	
	llint ans = calc(false);
	if(cnt[0] > 0){
		cnt[0]--;
		ans -= calc(true);
	}
	cout << ans << endl;
	return 0;
}