#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;

const int maxn = 5e5 + 10, P = 13331;
int n;
ull pw[maxn],sh[maxn],th[maxn];
char s[maxn];
void work() {
	scanf("%d%s", &n, s + 1);
	sh[0] = th[n + 1] = 0;
	for (int i = 1; i <= n; ++i) sh[i] = sh[i - 1] * P + (s[i] == '(') * 130 + 1;
	for (int i = n; i >= 1; --i) th[i] = th[i + 1] * P + (s[i] == '(') * 130 + 1;
	int lst = 0, cnt = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (cnt >= 0) {
			cnt += s[i] == '(' ? 1 : -1;
			if (cnt == 0) { lst = i, ans++, cnt = 0; continue; }
		}
		if (i - lst >= 2 && sh[i] - sh[lst] * pw[i - lst] == th[lst + 1] - th[i + 1] * pw[i - lst])
			lst = i, ans++, cnt = 0;
	}
	printf("%d %d\n", ans, n - lst);
}

int main() {
	pw[0] = 1;
	for (int i = 1; i <= 500000; ++i) pw[i] = pw[i - 1] * P;
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}