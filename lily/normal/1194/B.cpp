#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

int n, m;
char s[123113];
int a[123123], b[123123];

map <int, bool> c[123123];
void work() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) a[i] = 0, c[i].clear();
	for (int i = 1; i <= m; i++) b[i] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		for (int j = 1; j <= m; j++) {
			a[i] += s[j] == '*';
			b[j] += s[j] == '*';
			c[i][j] = s[j] == '*';
		}
	}
	int ans = 114514;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			ans = min(ans, n + m - 1 - a[i] - b[j] + c[i][j]);
		}
	printf("%d\n", ans);

}

int main() {
	int T;
	cin >> T;
	while (T--) {
		work();
	}
}