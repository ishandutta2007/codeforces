#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 300005;

int n, a[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		if (a[1] < a[n]) puts("YES");
		else puts("NO");
	}
	return 0;
}