#include <iostream>
#include <cstdio>

using namespace std;

const int N = 100005;

int n;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		if (n == 1) puts("-1");
		else {
			printf("2");
			for (int i = 1; i < n; i++) putchar('3');
			puts("");
		}
	}
	return 0;
}