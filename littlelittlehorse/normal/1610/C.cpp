#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, m, a[200001], b[200001], l;

bool check(int m) {
	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (c <= b[i] && m - (c + 1) <= a[i])
			++c;
		if (c == m)
			return true;
	}
	return false;
}

int main() {
	scanf("%d", &test);
	for (; test--; ) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &a[i], &b[i]);
		int l = 0, r = n + 1, m = (l + r) >> 1;
		for (; l + 1 < r; m = (l + r) >> 1)
			if (check(m))
				l = m;
			else
				r = m;
		printf("%d\n", l);
	}
}