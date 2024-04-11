#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

const int maxn = 1010, maxk = 60;
int n,p,k,dp[2][maxn][maxk][maxk];
bool a[maxn],b[maxn];

void f(int &x, int y){
	x = max(x, y);
}

int main(){
	scanf("%d%d%d", &n, &p, &k);
	int la,lb;
	scanf("%d", &la);
	for(int i = 1,x; i <= la; ++i)
		scanf("%d", &x), a[x] = 1;
	scanf("%d", &lb);
	for(int i = 1,x; i <= lb; ++i)
		scanf("%d", &x), b[x] = 1;
	
	if(p >= 2 * ceil(n * 1.0 / k)){
		int ans = 0;
		for(int i = 1; i <= n; ++i)
			ans += a[i] || b[i];
		return printf("%d", ans),0;
	}
	
	for(int j = 0; j <= p; ++j)
		for(int l = 0; l < k; ++l)
			for(int m = 0; m < k; ++m)
				dp[0][j][l][m] = -1e9;
	dp[0][p][0][0] = 0;
	
	for(int t = 1; t <= n; ++t){
		int i1 = t & 1, i = i1 ^ 1;
		for(int j = 0; j <= p; ++j)
			for(int l = 0; l < k; ++l)
				for(int m = 0; m < k; ++m)
					dp[i1][j][l][m] = -1e9;
		
		for(int j = 0; j <= p; ++j)
			for(int l = 0; l < k; ++l)
				for(int m = 0; m < k; ++m)
					if(dp[i][j][l][m] >= 0){
						f(dp[i1][j][max(l - 1, 0)][max(m - 1, 0)], dp[i][j][l][m] + ((a[t] && l > 0) || (b[t] && m > 0)));
						if(a[t] && j > 0) f(dp[i1][j - 1][k - 1][max(m - 1, 0)], dp[i][j][l][m] + 1);
						if(b[t] && j > 0) f(dp[i1][j - 1][max(l - 1, 0)][k - 1], dp[i][j][l][m] + 1);
					}
	}
	
	int i = n & 1, ans = 0;
	for(int j = 0; j <= p; ++j)
		for(int l = 0; l < k; ++l)
			for(int m = 0; m < k; ++m)
				ans = max(ans, dp[i][j][l][m]);
	printf("%d", ans);
	
	return 0;
}