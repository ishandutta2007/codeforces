#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

void work() {
	int n; scanf("%d", &n);
	if (n % 3 == 0) {
		for (int i = 1; i <= n / 3; ++i) printf("21");
	}
	else if (n % 3 == 1) {
		printf("1");
		for (int i = 1; i <= n / 3; ++i) printf("21");
	}
	else {
		printf("2");
		for (int i = 1; i <= n / 3; ++i) printf("12");
	}
	printf("\n");
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}