#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 1010;
int a[maxn],n;
void work() {
	scanf("%d", &n);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		for (int j = 1; j < i; ++j) ans = max(ans, a[i] + a[j]);
	}
	printf("%d\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}