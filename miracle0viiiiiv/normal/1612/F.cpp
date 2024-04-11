#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m, q, a[200005], b[200005];
int dp[200005], ndp[500005];
set<PII> hv;

void trans()
{
	rep1(i, n) ndp[i] = dp[i];
	rep1(i, n) if(dp[i] != 0) {
		int ni = i + dp[i] + (hv.find(MP(i, dp[i])) != hv.end()), fni = min(ni, n);
		ndp[fni] = max(ndp[fni], dp[i]);
		ndp[i] = max(ndp[i], ni);
	}
	for(int i = n - 1; i >= 1; i --) ndp[i] = max(ndp[i], ndp[i + 1]);
	rep1(i, n) dp[i] = min(ndp[i], m);
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	rep(i, q) scanf("%d%d", &a[i], &b[i]);
	if(n > m) {
		swap(n, m);
		rep(i, q) swap(a[i], b[i]);
	}
	rep(i, q) hv.insert(MP(a[i], b[i]));
	
	dp[1] = 1; for(int i = 2; i <= n; i ++) dp[i] = 0;
	int ans = 0;
	while(dp[n] < m) {
		trans(); ans ++;
	}
	printf("%d\n", ans);
	return 0;
}