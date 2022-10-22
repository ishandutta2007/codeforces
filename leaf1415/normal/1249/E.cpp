#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <utility>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n, c;
llint a[200005], b[200005];
llint dp[200005][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> c;
	for(int i = 2; i <= n; i++) cin >> a[i];
	for(int i = 2; i <= n; i++) cin >> b[i];
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 2; j++){
			dp[i][j] = inf;
		}
	}
	dp[1][0] = 0;
	
	for(int i = 1; i < n; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				llint cost = a[i+1];
				if(k == 1) cost = b[i+1];
				if(j == 0 && k == 1) cost += c;
				dp[i+1][k] = min(dp[i+1][k], dp[i][j] + cost);
			}
		}
	}
	
	for(int i = 1; i <= n; i++) cout << min(dp[i][0], dp[i][1]) << " "; cout << endl;
	
	return 0;
}