#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 60;
int n,p[maxn],f[maxn],tot;
void dfs(int nw) {
	if (nw == n + 1) {
		++tot;
		for (int i = 1; i <= n; ++i) printf("%d%c", p[i], " \n"[i == n]);
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (f[i] || (nw > 2 && p[nw - 1] + p[nw - 2] == i)) continue;
		p[nw] = i, f[i] = 1;
		dfs(nw + 1);
		f[i] = 0;
		if (tot == n) return;
	}
}
void work() {
	scanf("%d", &n); tot = 0;
	dfs(1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}