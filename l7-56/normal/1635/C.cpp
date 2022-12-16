#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 2e5 + 10;
int n,a[maxn];
void work() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	bool flag = 1;
	for (int i = 1; i < n; ++i) flag &= (a[i] <= a[i + 1]);
	if (flag) return printf("0\n"), void();
	if (a[n - 1] > a[n] || a[n] < 0) return printf("-1\n"), void();
	printf("%d\n", n - 2);
	for (int i = 1; i <= n - 2; ++i)
		printf("%d %d %d\n", i, n - 1, n);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}