#include <iostream>
#include <vector>
#define llint long long
#define mod 998244353

using namespace std;

llint n, k;
vector<llint> vec, vec2;
llint dp[200005][2], dp2[200005][2];

llint calc(vector<llint> &vec)
{
	for(int i = 0; i < (int)vec.size()-1; i++){
		if(vec[i] == vec[i+1] && vec[i] != -1) return 0;
	}
	
	llint ret = 1;
	int cnt = 0, pre = 0;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] == -1){
			if(cnt == 0 && i > 0) pre = vec[i-1];
			cnt++;
		}
		else{
			if(cnt > 0){
				if(pre == 0){
					for(int j = 0; j < cnt; j++) ret *= k-1, ret %= mod;
				}
				else{
					if(pre != vec[i]) ret *= dp[cnt][0], ret %= mod;
					else ret *= dp2[cnt][0], ret %= mod;
				}
			}
			cnt = 0;
		}
	}
	if(cnt > 0){
		if(pre == 0){
			ret = k;
			for(int i = 0; i < cnt-1; i++) ret *= k-1, ret %= mod;
		}
		else{
			for(int i = 0; i < cnt; i++) ret *= k-1, ret %= mod;
		}
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	llint a;
	for(int i = 0; i < n; i++){
		cin >> a;
		if(i%2) vec2.push_back(a);
		else vec.push_back(a);
	}
	
	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		dp[i+1][0] += dp[i][0] * (k-2), dp[i+1][0] %= mod;
		dp[i+1][1] += dp[i][0], dp[i+1][1] %= mod;
		dp[i+1][0] += dp[i][1] * (k-1), dp[i+1][0] %= mod;
	}
	dp2[0][1] = 1;
	for(int i = 0; i < n; i++){
		dp2[i+1][0] += dp2[i][0] * (k-2), dp2[i+1][0] %= mod;
		dp2[i+1][1] += dp2[i][0], dp2[i+1][1] %= mod;
		dp2[i+1][0] += dp2[i][1] * (k-1), dp2[i+1][0] %= mod;
	}
	
	cout << calc(vec) * calc(vec2) % mod << endl;
	return 0;
}