#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

void work() {
	int n; scanf("%d", &n);
	if (n > 19) return printf("NO\n"), void();
	printf("YES\n");
	for (int i = 1, val = 1; i <= n; ++i) {
		printf("%d%c", val, " \n"[i == n]);
		val *= 3;
	}
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}