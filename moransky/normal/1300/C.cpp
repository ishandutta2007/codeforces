#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100005;
int n, a[N], b[31];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		for (int j = 0; j <= 30; j++)
			if (a[i] >> j & 1) b[j]++;
	}
	int k = -1;
	for (int i = 30; ~i; i--) {
		if (b[i] == 1) {
			k = i;
			break;
		}
	}
	int p;
	for (int i = 1; i <= n; i++)
		if (k != -1 && a[i] >> k & 1) {
			p = i;
			printf("%d ", a[i]);
			break;
		}
	for (int i = 1; i <= n; i++) {
		if (i != p) printf("%d ", a[i]);
	}
	return 0;
}