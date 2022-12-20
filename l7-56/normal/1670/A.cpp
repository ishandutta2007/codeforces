#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 1e5 + 10;
int n, a[maxn];
void work() {
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]), cnt += (a[i] < 0), a[i] = abs(a[i]);
	for (int i = 1; i <= cnt; ++i) a[i] = -a[i];
	for (int i = 1; i < n; ++i) if (a[i] > a[i + 1]) return printf("NO\n"), void();
	printf("YES\n");
}

int main() {
	int T; scanf("%d", &T);
	while (T--) work();
	return 0;
}