#include <bits/stdc++.h>
using namespace std;

int t;
int n;
map<int, int> cnt;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		cnt.clear();
		bool ans = false;
		for (int i = 0; i < n; i++) {
			int b; scanf("%d", &b);
			if (++cnt[b] > 1) {
				ans = true;
			}
		}
		if (ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}