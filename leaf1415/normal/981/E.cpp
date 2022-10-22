#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define llint long long
#define mod 1000000007

using namespace std;

llint n, q;
vector<llint> vec[10005][2];
llint dp[10005];
bool ans[10005];

int main(void)
{
	cin >> n >> q;
	llint l, r, x;
	for(int i = 0; i < q; i++){
		cin >> l >> r >> x;
		vec[l][0].push_back(x);
		vec[r][1].push_back(x);
	}
	
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		bool flag = false;
		for(int j = 0; j < vec[i][0].size(); j++){
			flag = true;
			llint a = vec[i][0][j];
			for(int k = n; k >= 0; k--){
				if(k - a >= 0) dp[k] += dp[k-a], dp[k] %= mod;
			}
		}
		if(flag){
			for(int j = 1; j <= n; j++){
				if(dp[j]) ans[j] = true;
			}
		}
		for(int j = 0; j < vec[i][1].size(); j++){
			llint a = vec[i][1][j];
			for(int k = 0; k <= n; k++){
				if(k + a <= n) dp[k+a] += mod - dp[k], dp[k+a] %= mod;
			}
		}
	}
	
	int cnt = 0;
	for(int i = 1; i <= n; i++) if(ans[i]) cnt++;
	cout << cnt << endl;
	for(int i = 1; i <= n; i++) if(ans[i]) cout << i << " ";
	cout << endl;
	
	return 0;
}