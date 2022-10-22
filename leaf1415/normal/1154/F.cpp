#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
int a[200005], sum[2005];
int off[200005];
int dp[2005];

int main(void)
{
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for(int i = 1; i <= k; i++) sum[i] = sum[i-1] + a[i];
	
	int x, y;
	for(int i = 1; i <= m; i++){
		cin >> x >> y;
		off[x] = max(off[x], y);
	}
	
	for(int i = 1; i <= k; i++) dp[i] = 1e9;
	for(int i = 0; i < k; i++){
		for(int j = 1; j <= k; j++){
			if(i+j <= k) dp[i+j] = min(dp[i+j], dp[i] + sum[i+j] - sum[i+off[j]]);
		}
	}
	cout << dp[k] << endl;
	return 0;
}