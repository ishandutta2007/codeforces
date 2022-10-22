#include <bits/stdc++.h>
using namespace std;

int t;
int x;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &x);
		int ans = 0;
		while (x > 0) {
			x -= ++ans;
		}
		if (x == -1) {
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}