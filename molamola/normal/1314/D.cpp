#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

int n, k;
ll V[88][88];
const ll INF = 1e16;
int color[88];

int main() {
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
		scanf("%lld", V[i] + j);
	}
	for(int i=1;i<=n;i++) V[i][i] = INF;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	auto rand_int = [&](int l, int r) {
		return uniform_int_distribution<int>(l, r)(rng);
	};
	ll ans = INF;
	while(1) {
		double tm = (double)clock() / CLOCKS_PER_SEC;
		if(tm > 2.4) break;
		color[1] = 1;
		for(int i=2;i<=n;i++) color[i] = rand_int(1, 2);
		ll dp[12][88] = {};
		rep(t, k+1) for(int i=1;i<=n;i++) dp[t][i] = INF;
		dp[0][1] = 0;
		for(int i=1;i<=k;i++) {
			for(int j=1;j<=n;j++) for(int u=1;u<=n;u++) if(color[j] != color[u]) {
				dp[i][u] = min(dp[i][u], dp[i-1][j] + V[j][u]);
			}
		}
		ans = min(ans, dp[k][1]);
	}
	printf("%lld\n", ans);
	return 0;
}