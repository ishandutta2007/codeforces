#include <iostream>

using namespace std;

int n, k;
int a[100005];
int t[100005];
int sum[100005];

int main(void)
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> t[i];
	
	int all = 0;
	for(int i = 1; i <= n; i++){
		if(t[i]) all += a[i];
	}
	
	for(int i = 1; i <= n; i++){
		if(t[i]) sum[i] = sum[i-1];
		else sum[i] = sum[i-1] + a[i];
	}
	
	int ans = 0;
	for(int i = 1; i <= n-k+1; i++){
		ans = max(ans, all + sum[i+k-1] - sum[i-1]);
	}
	cout << ans << endl;
	
	return 0;
}