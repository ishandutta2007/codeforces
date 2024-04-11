#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 5003
#define K 2501


int main(){
	int a[N];
	int dp[N][K][2];
	f(i, N){
		f(j, K){
			dp[i][j][0] = 1000000009;
			dp[i][j][1] = 1000000009;
		}
		dp[i][0][0] = 0;
	}
	int n;
	int x, y;

	scanf("%d", &n);
	f(i, n){
		scanf("%d", &a[i + 1]);
	}
	a[0] = -10000;
	a[n + 1] = -10000;

	dp[1][1][1] = max(a[0] - a[1] + 1, 0) + max(a[2] - a[1] + 1, 0);
	for (int i = 2; i <= n; i++){

		for (int j = 1; j <= ((i + 1) / 2); j++){
			if ((2 * j) < (i + 1)){
				dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1]);
			}
			x = dp[i - 2][j - 1][1] + max(min(a[i - 2] - 1, a[i - 1]) - a[i] + 1, 0) + max(a[i + 1] - a[i] + 1, 0);
			y = dp[i - 2][j - 1][0] + max(a[i - 1] - a[i] + 1, 0) + max(a[i + 1] - a[i] + 1, 0);
			dp[i][j][1] = min(x, y);
		}
	}

	for (int i = 1; i <= (n + 1) / 2; i++){
		printf("%d", min(dp[n][i][0], dp[n][i][1]));
		if (i + 1 <= (n + 1) / 2)printf(" ");
		else printf("\n");
	}


	return 0;
}