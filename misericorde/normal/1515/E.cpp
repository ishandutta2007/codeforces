#include <bits/stdc++.h>

int n,mod,f[404][404][404],ans;
using ll = long long;

int dec(int x) { return x >= mod ? x - mod : x; }

int main() {
	scanf("%d%d",&n,&mod);
	f[2][1][1] = 1;
	for (int i = 2; i <= n; ++ i) 
	for (int j = 1; j < i; ++ j) 
	for (int k = 1; k <= n; ++ k) {
		int w = f[i][j][k];
		// does not link
		f[i+1][j+1][k+1] = dec(f[i+1][j+1][k+1] + (ll) w * (j + 1) % mod);
		// link with left side
		f[i+1][j][k+2] = dec(f[i+1][j][k+2] + (ll) 2 * w * j % mod);
		f[i+1][j][k+1] = dec(f[i+1][j][k+1] + (ll) 2 * w * j % mod);
		// link with right side

		// link with both sides
		f[i+1][j-1][k+3] = dec(f[i+1][j-1][k+3] + (ll) w * (j - 1) % mod);
		f[i+1][j-1][k+2] = dec(f[i+1][j-1][k+2] + (ll) 2 * w * (j - 1) % mod);
	//	f[i+1][j-1][k+1] = (f[i+1][j-1][k+1] + (ll) w * (j - 1) % mod) % mod;
	} 
	for (int i = 1; i <= n; ++ i) {
	//	printf("%d ",f[i+1][1][n]);
		ans = (ans + f[i+1][1][n]) % mod;
	}
	printf("%d",ans);
	return 0;
}