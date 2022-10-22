#include <bits/stdc++.h>
using namespace std;

int n;
char s[65005];
int ans;

int main() {
	scanf("%d", &n);
	scanf(" %s", s);
	for (int i = 0; i < n; i++) {
		int cur = s[i] - '0';
		if (cur % 2 == 0) ans += i + 1;
	}
	printf("%d\n", ans);
	return 0;
}