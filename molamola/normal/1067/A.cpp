#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;
typedef pair<double, double> pdd;

const int MOD = 998244353;
int n, A[100010];
int dp[100010][210][2];

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", A+i);
	if(A[1] == -1) {
		for(int i=1;i<=200;i++) dp[1][i][0] = 1;
	}
	else {
		dp[1][A[1]][0] = 1;
	}
	for(int i=2;i<=n;i++) {
		ll sum[210][2] = {};
		for(int j=1;j<=200;j++) sum[j][0] = (sum[j-1][0] + dp[i-1][j][0] + dp[i-1][j][1]) % MOD;
		for(int j=200;j;j--) sum[j][1] = (sum[j+1][1] + dp[i-1][j][1]) % MOD;
		for(int j=1;j<=200;j++) {
			dp[i][j][0] = (int)sum[j-1][0];
			dp[i][j][1] = ((ll)dp[i-1][j][0] + dp[i-1][j][1] + sum[j+1][1]) % MOD;
		}
		if(A[i] != -1) for(int j=1;j<=200;j++) if(j != A[i]) dp[i][j][0] = dp[i][j][1] = 0;
	}
	ll ans = 0;
	for(int i=1;i<=200;i++) ans = (ans + dp[n][i][1]) % MOD;
	printf("%lld\n", ans);
	return 0;
}