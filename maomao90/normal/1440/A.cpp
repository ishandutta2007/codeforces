#include <bits/stdc++.h>
using namespace std;

int t;
int n, c0, c1, h;
char s[1005];
int ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &n, &c0, &c1, &h);
		scanf(" %s", s);
		ans = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				ans += min(c0, c1 + h);
			} else {
				ans += min(c1, c0 + h);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}