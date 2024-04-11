#include <bits/stdc++.h>
using namespace std;

int n;
int ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char c; scanf(" %c", &c);
		if (c == '-') ans--;
		else ans++;
		ans = max(0, ans);
	}
	printf("%d\n", ans);
	return 0;
}