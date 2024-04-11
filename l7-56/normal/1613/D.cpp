#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
using namespace std;

const int maxn = 5e5 + 10, mod = 998244353;
int T,n,a[maxn],f[maxn],g[maxn][2],s[maxn][3],ans;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			f[i] = (s[a[i]][0] + (a[i] ? s[a[i] - 1][0] : 0) + (a[i] == 0)) % mod;
			g[i][0] = (s[a[i]][1] + s[a[i] + 2][2]) % mod;
			g[i][1] = (s[a[i]][2] + (a[i] >= 2 ? (s[a[i] - 2][1] + s[a[i] - 2][0]) % mod : 0) + (a[i] == 1)) % mod;
			s[a[i]][0] = (s[a[i]][0] + f[i]) % mod;
			s[a[i]][1] = (s[a[i]][1] + g[i][0]) % mod;
			s[a[i]][2] = (s[a[i]][2] + g[i][1]) % mod;
			ans = (ans + (f[i] + (g[i][0] + g[i][1]) % mod) % mod) % mod;
		}
		printf("%d\n", ans);
		for(int i = 1; i <= n; ++i) s[a[i]][0] = s[a[i]][1] = s[a[i]][2] = 0;
		ans = 0;
	}
	return 0;
}