#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int P = 998244353;
const int INV = P / 2 + 1;
const int N = 500 + 10;

int f[N][N], cnt[N];
int n, k, ans = 0;

int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		memset(f, 0, sizeof(f));
		f[1][1] = 2;
		for(int j = 2; j <= n; j++) {
			int minn = min(i, j);
			for(int k = 1; k <= minn; k++) {
				f[j][1] += f[j - 1][k];
				if(f[j][1] >= P) f[j][1] -= P;
				if(k != 1) f[j][k] = f[j - 1][k - 1];
			}
		}
		for(int j = 1; j <= i; j++) {
			cnt[i] += f[n][j];
			if(cnt[i] >= P) cnt[i] -= P;
		}
	}
	for(int i = n; i >= 1; i--) {
		cnt[i] = cnt[i] - cnt[i - 1];
		if(cnt[i] < 0) cnt[i] += P;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i * j >= k) break;
			ll tmp = (ll)(cnt[i]) * (ll)(cnt[j]);
			tmp %= (ll)P; tmp *= (ll)(INV); tmp %= (ll)P;
			ans += (int)tmp; if(ans >= P) ans -= P;
		}
	}
	cout << ans << endl;
	return 0;
}