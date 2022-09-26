#include<bits/stdc++.h>
#define int long long
using namespace std;

string num;
int mod;
int dp[262144][105];
signed main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cin >> num >> mod;
	int sz = num.size();
	sort(num.begin(),num.end());
	dp[0][0] = 1;
	for(int mask = 0;mask < (1 << sz);++mask) {
		for(int i = 0;i < mod;++i) {
			if(dp[mask][i] == 0) continue;
			for(int j = 0;j < sz;++j) {
				if((mask >> j) & 1) continue;
				if(mask == 0 && num[j] == '0') continue;
				if(j > 0 && num[j] == num[j - 1] && ((mask >> (j-1)) & 1) == 0) continue;
				dp[mask | (1 << j)][(i * 10 + num[j] - '0') % mod] += dp[mask][i];
			}
		}
	}
	cout << dp[(1 << sz) - 1][0] << endl;
}