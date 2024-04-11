#include <bits/stdc++.h>
using namespace std;

int t;
int a, b, c;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &a, &b, &c);
		int curMin = min(a, min(b, c));
		int sum = a + b + c;
		if (sum % 9 != 0) {
			printf("NO\n");
			continue;
		}
		int times = sum / 9;
		if (times > curMin) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
	return 0;
}