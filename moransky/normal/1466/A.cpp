#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 55;

int n, a[N], b[N * N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n); int tot = 0;
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (a[j] != a[i]) b[++tot] = a[j] - a[i];
		sort(b + 1, b + 1 + tot);
		int cnt = 0;
		if (tot >= 1) cnt++;
		for (int i = 2; i <= tot; i++)
			if (b[i] != b[i - 1]) cnt++;
		printf("%d\n", cnt);
	}	
	return 0;
}