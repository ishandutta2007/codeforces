#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 200005;

int n;
char s[N];


int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == 'R') {
				ans = max(ans, i);
				break;
			}
		}
		for (int i = n; i; i--) {
			if (s[i] == 'R') {
				ans = max(ans, n + 1 - i);
				break;
			}
		}

		if (ans == 0) {
			printf("%d\n", n + 1);
		} else {
			int last = 0;
			for (int i = 1; i <= n; i++) {
				if (s[i] == 'R') {
					ans = max(ans, i - last);
					last = i;
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}