#include <bits/stdc++.h>
using namespace std;

int t;
int n;
char s[300005];
int ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf(" %s", s);
		ans = 0;
		char prev = '-';
		bool all = true;
		for (int i = 0; i < n; i++) {
			if (prev != '-') {
				if (s[i] != '-' && s[i] != prev) all = false;
			} else if (s[i] != '-') prev = s[i];
		}
		if (all) printf("%d\n", n);
		else {
			int cur = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] == '-') cur++;
				else if (cur != 0) {
					ans += cur + 1;
					cur = 0;
				}
			}
			if (cur != 0) ans += cur + 1;
			if (s[0] == '-' && s[n - 1] == '-') ans--;
			printf("%d\n", ans);
		}
	}
	return 0;
}