#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 110;
int n;
char s[maxn];
void work() {
	scanf("%d%s", &n, s + 1);
	int ans = 0, lst = -2;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '1') continue;
		ans += max(0, 2 - (i - lst - 1));
		lst = i;
	}
	printf("%d\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}