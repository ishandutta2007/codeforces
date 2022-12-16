#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 1e5 + 10, maxa = 2e7 + 10;
ll dp[maxa];
int a[maxn],c[maxa],n,mxa,p[maxa],cntp,v[maxa];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), c[a[i]]++, mxa = max(mxa, a[i]);
	
	for(int i = 2; i <= mxa; ++i) {
		if(v[i] == 0) p[++cntp] = i, v[i] = i;
		for(int j = 1; i * p[j] <= mxa && p[j] <= v[i] && j <= cntp; ++j) v[i * p[j]] = p[j];
	}
	
	for(int i = 1; i <= cntp; ++i)
		for(int j = mxa / p[i]; j; --j) c[j] += c[j * p[i]];
	
	for(int i = mxa; i; --i) {
		dp[i] = (ll)c[i] * i;
		for(int j = 1; i * p[j] <= mxa && j <= cntp; ++j)
			dp[i] = max(dp[i], dp[i * p[j]] + (ll)(c[i] - c[i * p[j]]) * i);
	}
	printf("%lld\n", dp[1]);
	return 0;
}