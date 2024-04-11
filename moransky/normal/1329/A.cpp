#include <iostream>
#include <cstdio>

using namespace std;

const int N = 100005;

int n, m, l[N], ans[N];

typedef long long LL;

LL s = 0;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d", l + i), s += l[i];
	if (s < n) {
		puts("-1");
		return 0;
	}
	if (l[m] > n - (m - 1)) {
		puts("-1");
		return 0;
	}
	
	int j = n - l[m] + 1;
	int d = (j - 1) - (m - 1);
	ans[m] = j;
	for (int i = m - 1; i; i--) {
		j -= min(d + 1, l[i]) ;
		d -= min(d + 1, l[i]) - 1;
		if (j + l[i] - 1 > n) {
			puts("-1");
			return 0;
		}
		ans[i] = j;
	}
	for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
	return 0;
}