#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second


const int N = 1005;
const int MOD = 998244353;
int n, m;
vector <int> E[N];
int a[N], q[N], deg[N], mark[N], em[N];
LL cnt[N];

void work() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) E[i].clear();
	for (int i = 1; i <= n; i++) deg[i] = 0, cnt[i] = 0, em[i] = 0;
	for (int i = 1; i <= m; i++) {
		int x, y; read(x); read(y);
		E[x].push_back(y); deg[y]++;
	}
	int he = 1, ta = 1;
	for (int i = 1; i<= n; i++) if (!deg[i]) q[ta++] = i;
	while (he < ta) {
		int x = q[he++];
		cnt[x] += a[x];
		cnt[x] %= MOD;
		for (auto v : E[x]) {
			cnt[v] += cnt[x];
			cnt[v] %= MOD;
			if (--deg[v] == 0) {
				q[ta++] = v;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int cm = 0;
		for (int j = 1; j <= n; j++) {
			if (a[j] > 0) mark[j] = 1, cm++;
			else {
				mark[j] = 0;
				em[j] ++;
			}
		}
		if (!cm) {
			printf("%d\n", i - 1);
			return;
		}
		for (int j = 1; j <= n; j++) if (mark[j]) {
			a[j]--;
			for (auto v : E[j]) a[v] ++;
		}
	}
	LL ans = cnt[q[n]] + em[q[n]];
	ans %= MOD;
	ans += MOD;
	ans %= MOD;
	printf("%d\n", (int) ans);
}

int main() {
	int T;
	read(T);
	while (T--) work();
}