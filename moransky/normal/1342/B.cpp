#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 105;

char t[N];

int n;

bool inline check() {
	for (int i = 1; i <= n; i++) {
		if (t[i] != t[1]) return false;
	}
	return true;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", t + 1);
		n = strlen(t + 1);
		if (check()) {
			for (int i = 1; i <= n; i++) putchar(t[i]);
			puts("");
		} else {
			for (int i = 1; i <= n; i++) {
				printf("01");
			}
			puts("");
		}
	}
	return 0;
}