// Skyqwq
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 2e5 + 5;

int n, a[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		bool ok = false;
		for (int i = 2; i <= n; i++)
			if (a[i] != a[1]) ok = true;
		if (ok) printf("%d\n", 1);
		else printf("%d\n", n);
	}
	return 0;
}