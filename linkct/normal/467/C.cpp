#include <cstdio>
#include <iostream>
#define MAXN 5005
typedef long long int ll;
using namespace std;

int seq[MAXN], n, m, k;
ll f[MAXN], dp[MAXN][MAXN];

int main(){
	int i, j;
	scanf("%d%d%d", &n, &m, &k);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &seq[i]);
		f[i] = f[i - 1] + seq[i];
	}
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= k; ++ j){
			dp[i][j] = dp[i - 1][j];
			if(i >= m) dp[i][j] = max(dp[i][j], dp[i - m][j - 1] - f[i - m] + f[i]);
		}
	cout << dp[n][k] << endl;
	return 0;
}