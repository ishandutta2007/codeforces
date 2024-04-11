#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)


int ans[100];
void dfs(int x, int y) {
	if (y > 10) return;
	if (x > 30) return;
	if (ans[x] > y) ans[x] = y;
	else return;
	dfs(abs(x + 2), y + 1);
	dfs(abs(x - 2), y + 1);
	dfs(abs(x + 3), y + 1);
	dfs(abs(x - 3), y + 1);
}

void work() {
	int n;
	read(n);
	if (n < 24) printf("%d\n", ans[n]);
	else printf("%d\n", (n - n % 12 - 12) / 3 + ans[n % 12 + 12]);
}

int main() {
	memset(ans, 0x3f, sizeof ans);
	dfs(0, 0);
	int T;
	read(T);
	while (T--) work();
}