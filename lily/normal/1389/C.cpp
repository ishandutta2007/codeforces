#include <bits/stdc++.h>
using namespace std;

char s[201111];

void work() {
	scanf("%s", s + 1);
	int n = strlen(s + 1), ans = 0;
	for (int i = '0'; i <= '9'; i++) {
		for (int j = '0'; j <= '9'; j++) {
			int m = 0;
			for (int k = 1; k <= n; k++) {
				if (s[k] == (m & 1 ? j : i)) {
					m++;
				}
			}
			ans = max(ans, i == j ? m : (m / 2 * 2));
		}
	}
	printf("%d\n", n - ans);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) work();

}