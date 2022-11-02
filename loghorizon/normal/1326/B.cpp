#include <iostream>
#include <cstdio>

using namespace std;

const int N = 200005;

int n, b[N], a[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", b + i);
	a[1] = b[1];
	int v = a[1];
	for (int i = 2; i <= n; i++) {
		a[i] = v + b[i];
		v = max(v, a[i]);
	}
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	return 0;
}