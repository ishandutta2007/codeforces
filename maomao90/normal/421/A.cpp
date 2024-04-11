#include <bits/stdc++.h>
using namespace std;

int n, a, b;
int x[105], y[105];

int main() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < a; i++) {
		int temp; scanf("%d", &temp);
		x[temp] = 1;
	}
	for (int i = 0; i < b; i++) {
		int temp; scanf("%d", &temp);
		y[temp] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (x[i]) printf("1 ");
		else printf("2 ");
	}
	printf("\n");
	return 0;
}