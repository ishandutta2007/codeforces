#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint dp[2][19];
llint a[300005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint m = -1, k;
	for(int t = n; t; t/=2) m++;
	for(int i = 1; i <= n; i++){
		if(a[i] == -1) k = i;
	}
	for(int i = 1; i < k; i++) a[i] = 0;
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j <= m; j++){
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= m; j++) dp[(i+1)%2][j] = inf;
		for(int j = 0; j <= m; j++){
			llint num = i;
			if(i >= k) num--;
			num -= j;
			if(i+1 != k && j < m && num >= (1<<(j+1))-(j+2)) dp[(i+1)%2][j+1] = min(dp[(i+1)%2][j+1], dp[i%2][j] + a[i+1]);
			dp[(i+1)%2][j] = min(dp[(i+1)%2][j], dp[i%2][j]);
		}
		/*for(int j = 0; j <= m; j++){
			cout << dp[(i+1)%2][j] << " ";
		}
		cout << endl;*/
	}
	/*for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << dp[n%2][m] << endl;
	
	return 0;
}