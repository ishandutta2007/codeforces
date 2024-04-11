#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 2e5 + 10;
int n,a[maxn];
void work() {
	int flg = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] == 1) flg = 1;
	}
	sort(a + 1, a + n + 1);
	if (flg) {
		for (int i = 1; i < n; ++i)
			if (a[i] + 1 == a[i + 1]) return printf("NO\n"), void();
		printf("YES\n");
	}
	else printf("YES\n");
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}