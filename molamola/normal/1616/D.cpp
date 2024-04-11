#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using t3 = tuple<int, int, int>;

int n, a[50050], dp[50050][4];

void solve() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", a + i);
	int x; scanf("%d", &x);
	for(int i=1;i<=n;i++) a[i] -= x;
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	auto upd = [&](int &a, int b) {
		if(a < b) a = b;
	};
	for(int i=1;i<=n;i++) {
		rep(j, 4) {
			if(dp[i-1][j] == -1) continue;
			int v = dp[i-1][j];
			int c1 = (j & 1), c2 = (j & 2);
			upd(dp[i][c1*2], v);
			if(c1 && a[i] + a[i-1] < 0) continue;
			if(c1 && c2 && a[i] + a[i-1] + a[i-2] < 0) continue;
			upd(dp[i][c1*2+1], v + 1);
		}
	}
	printf("%d\n", *max_element(dp[n], dp[n]+4));
}

int main() {
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		solve();
	}
	return 0;
}