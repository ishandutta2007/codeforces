#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pii pair<int, int>
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
const int N = 1e6 + 10;
int n, m;
int ax[N], ay[N], tot = 0;
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i * 2 <= n; i++) {
		for(int j = 1; j <= m; j++) {
			ax[++tot] = i, ay[tot] = j;
			ax[++tot] = n + 1 - i, ay[tot] = m + 1 - j;
		}
	}
	if(n & 1) {
		for(int i = 1; i * 2 <= m; i++) {
			ax[++tot] = (n + 1) / 2, ay[tot] = i;
			ax[++tot] = (n + 1) / 2, ay[tot] = m + 1 - i;
		}
		if(m & 1) ax[++tot] = (n + 1) / 2, ay[tot] = (m + 1) / 2;
	}
	for(int i = 1; i <= tot; i++) printf("%d %d\n", ax[i], ay[i]);
	return 0;
}