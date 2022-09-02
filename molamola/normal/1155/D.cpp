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
#include <bitset>
#include <time.h>
#include <limits.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb push_back
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

ll dp[300030][4];
int n, X, A[300030];

int main() {
	scanf("%d%d", &n, &X);
	for(int i=1;i<=n;i++) scanf("%d", A + i);
	for(int i=1;i<=n;i++) rep(j, 4) dp[i][j] = -1e18;
	ll ans = 0;
	for(int i=1;i<=n;i++) {
		dp[i][0] = 0;
		dp[i][1] = dp[i-1][1] + A[i];
		dp[i][2] = dp[i-1][2] + (ll) X * A[i];
		dp[i][3] = dp[i-1][3] + A[i];
		for(int j=1;j<4;j++) dp[i][j] = max(dp[i][j], dp[i][j-1]);
		ans = max(ans, dp[i][3]);
	}
	printf("%lld\n", ans);
	return 0;
}