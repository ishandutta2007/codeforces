#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

int n;
int a[1123312];
int main() {

	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] % 2) {
			a[i] = (abs(a[i]) + (cur ^ (a[i] < 0))) / 2 * (a[i] < 0 ? -1 : 1);
			cur ^= 1;
		}
		else a[i] /= 2;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", a[i]);
	}
}