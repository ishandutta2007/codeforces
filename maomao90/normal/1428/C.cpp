#include <bits/stdc++.h>
using namespace std;

int t;
int n;
char s[200005];

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(s, 0, sizeof s);
		int cnt = 0;
		scanf(" %s", s);
		n = strlen(s);
		for (int i = 0; i < n; i++) {
			if (s[i] == 'B') {
				if (cnt == 0) cnt++;
				else cnt--;
			} else cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}