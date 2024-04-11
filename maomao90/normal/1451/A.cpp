#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int divide, ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n == 1) {
			printf("0\n");
		} else if (n == 2) {
			printf("1\n");
		} else if (n % 2 == 0 || n == 3) {
			printf("2\n");
		} else printf("3\n");
	}
	return 0;
}