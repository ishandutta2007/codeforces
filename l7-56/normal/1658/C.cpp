#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 1e5 + 10;
int n,a[maxn];
void work() {
	scanf("%d", &n);
	int pos = -1;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] == 1) {
			if (pos == -1) pos = i;
			else pos = -2;
		}
	}
	if (pos < 0) return printf("NO\n"), void();
	for (int i = pos, j = pos % n + 1; j != pos; i = i % n + 1, j = j % n + 1)
		if (a[j] - a[i] > 1) return printf("NO\n"), void();
	printf("YES\n");
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}