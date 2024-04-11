#include <bits/stdc++.h>
using namespace std;
const int N = 5001;

int dp[N][N];
int n;

int main(){
// 	freopen("input.txt","r",stdin);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)scanf("%d", &dp[i][i]);
	for(int j = 1; j <= n;j ++)
		for(int i = 0; i + j < n; i++) {
			int l = i + j;
			dp[i][l] = dp[i][l - 1] ^ dp[i + 1][l]; 
		}
	for(int j = 1; j <= n; j++)
		for(int i = 0; i + j < n; i++) {
			int l = i + j;
			dp[i][l] = max(dp[i][l], max(dp[i][l - 1],dp[i + 1][l])); 
		}
	scanf("%d", &n);
	for(int i = 0, l, r; i < n; i++) {
		scanf("%d %d", &l, &r);
		l--; r--;
		printf("%d\n", dp[l][r]);
	}
	return 0;
}