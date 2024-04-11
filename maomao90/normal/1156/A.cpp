#include <bits/stdc++.h>
using namespace std;

int n;
int a[105];
int ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		if (a[i - 1] == a[i]) {
			printf("Infinite\n");
			return 0;
		}
		switch (a[i - 1]) {
			case 1:
				if (a[i] == 2) {
					ans += 3;
					if (i >= 2 && a[i - 2] == 3) ans--;
				}
				else ans += 4;
				break;
			case 2:
				if (a[i] == 1) ans += 3;
				else {
					printf("Infinite\n");
					return 0;
				}
				break;
			case 3:
				if (a[i] == 1) ans += 4;
				else {
					printf("Infinite\n");
					return 0;
				}
				break;
		}
	}
	printf("Finite\n%d\n", ans);
	return 0;
}