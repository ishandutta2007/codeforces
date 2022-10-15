#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)

const int N = 2e5 + 5;
const int MOD = 998244353;

int n, K;
int f[2][N], g[N];
void work() {
	read(n); read(K);
	int lo = 0, cur = 0, nxt = 1;
	f[cur][0] = 1;
	for (int i = K; lo <= n; i++) {
		memset(f[nxt], 0, sizeof f[nxt]);
		for (int j = lo; j + i <= n; j++) {
			f[nxt][j + i] = (f[nxt][j + i] + (f[cur][j] + f[nxt][j]) % MOD) % MOD;
		}
		lo += i;
		for (int j = lo; j <= n; j++) {
			g[j] = (g[j] + f[nxt][j]) % MOD;
		}
		swap(cur, nxt);
	}
	
	for (int i = 1; i <= n; i++) printf("%d%c", g[i], i == n ? '\n' : ' ');
}

int main() {
	work();
}