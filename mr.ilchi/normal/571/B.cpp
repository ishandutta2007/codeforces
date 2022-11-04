#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[1<<20];
long long dp[5010][5010];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a,a+n);
	int c0 = n%k, c1=k-n%k;
	int l0 = n/k+1, l1=n/k;
	dp[0][0] = 0;
	for (int i=0; i<=c0; i++)
		for (int j=0; j<=c1; j++) if (i || j){
			int cnt = i*l0 + j*l1;
			dp[i][j] = 1LL<<60;
			if (i)
				dp[i][j] = min(dp[i][j], dp[i-1][j] + a[cnt-1] - a[cnt-l0]);
			if (j)
				dp[i][j] = min(dp[i][j], dp[i][j-1] + a[cnt-1] - a[cnt-l1]);
		}
	cout << dp[c0][c1] << endl;
	return 0;
}