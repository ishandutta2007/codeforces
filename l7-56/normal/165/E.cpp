#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int dp[1 << 22],a[maxn],n;

int main(){
	memset(dp, -1, sizeof dp);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), dp[a[i]] = a[i];
	for(int i = 1; i < (1 << 22); ++i)
		for(int j = 0; j < 22; ++j){
			if(!(i & (1 << j)) || dp[i ^ (1 << j)] == -1) continue;
			dp[i] = dp[i ^ (1 << j)]; break;
		}
	for(int i = 1; i <= n; ++i){
		int x = 0;
		for(int j = 0; j < 22; ++j)
			x |= ((1 ^ (a[i] >> j & 1)) << j);
		printf("%d ", dp[x]);
	}
	return 0;
}
//CF165E