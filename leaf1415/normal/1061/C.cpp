#include <iostream>
#include <vector>
#define llint long long
#define mod 1000000007

using namespace std;

llint n;
llint a[100005];
llint dp[100005];
vector<llint> vec[1000005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i < 100005; i++){
		for(int j = 1; i*j < 1000005; j++){
			vec[i*j].push_back(i);
		}
	}
	
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = vec[a[i]].size()-1; j >= 0; j--){
			dp[vec[a[i]][j]] += dp[vec[a[i]][j]-1];
			dp[vec[a[i]][j]] %= mod;
		}
	}
	
	llint ans = 0;
	for(int i = 1; i <= n; i++) ans += dp[i], ans %= mod;
	cout << ans << endl;
	
	return 0;
}