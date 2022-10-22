#include <bits/stdc++.h>

using namespace std;
const int N = 21, M = 31607;
int n;
int a[N][N], vis[N][N];
int res[N][1 << N], all[N], L2[1 << N];

int power(int a, int b, int c = 1) {
	for(; b; b >>= 1, a = a * a % M)
		if(b & 1)
			c = c * a % M;
	return c;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) L2[1 << i] = i;
	for(int i = 0; i < n; i++) {
		all[i] = 1;
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
			a[i][j] = a[i][j] * power(10000, M - 2) % M;
			all[i] = all[i] * a[i][j] % M;
		}
	}
	for(int i = 0; i < n; i++) {
		res[i][0] = 1;
		for(int j = 1; j < (1 << n); j++) {
			int t = j & (-j);
			res[i][j] = res[i][j ^ t] * a[L2[t]][i] % M;
		}
	}
	int ans = 0;
	for(int msk = 0; msk < (1 << (n + 2)); msk++) {
		int prod = 1;
		for(int i = 0; i < n + 2; i++) if(msk >> i & 1) prod = M - prod;
		for(int i = 0; i < n; i++) {
			if(msk >> i & 1) {
				prod = prod * all[i] % M;
			}
		}
		if(msk >> n & 1) {
			for(int i = 0; i < n; i++) {
				if(!(msk >> i & 1)) {
					prod = prod * a[i][i] % M; 
				}
			}
		}
		if(msk >> (n + 1) & 1) {
			for(int i = 0; i < n; i++) {
				if(!(msk >> i & 1)) {
					if((msk >> n & 1) && i == n - 1 - i) continue;
					prod = prod * a[i][n - 1 - i] % M;
				}
			}
		}
		for(int i = 0; i < n; i++) {
			int now = msk & ((1 << n) - 1);
			if(msk >> n & 1) now |= (1 << i);
			if(msk >> (n + 1) & 1) now |= (1 << (n - 1 - i));
			now = ((1 << n) - 1) ^ now;
			prod = prod * (1 - res[i][now] + M) % M;
		}
		ans = (ans + prod) % M;
	}
	ans = (1 + M - ans) % M;
	cout << ans << endl;
	return 0;
}