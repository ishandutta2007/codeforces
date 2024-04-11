#include <bits/stdc++.h>
using namespace std;

int t;
char s[200005];
int ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		memset(s, 0, sizeof s);
		scanf(" %s", s);
		int prev = -1;
		for (int i = 0; i < strlen(s); i++) {
			if (s[i] == 'R') ans = max(ans, i - prev), prev = i;
		}
		ans = max(ans, (int) strlen(s) - prev);
		printf("%d\n", ans);
	}
	return 0;
}