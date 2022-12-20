#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
int cnt[maxn << 1];
void work() {
	int n,m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cnt[max(abs(i - 1), abs(n - i)) + max(abs(j - 1), abs(m - j))]++;
	for (int i = 0; i <= n + m; ++i)
		while (cnt[i]) printf("%d ", i), cnt[i]--;
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}