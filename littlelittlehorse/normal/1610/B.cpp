#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, m, a[200001], b[200001], l;

int main() {
	scanf("%d", &test);
	for (; test--; ) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		bool ok = true;
		int bad1 = 0, bad2 = 0;
		for (int i = 1, j = n; i < j && ok; i++, j--)
			if (a[i] != a[j]) {
				ok = false;
				bad1 = a[i];
				bad2 = a[j];
			}
		if (ok) {
			printf("YES\n");
			continue;
		}
		l = 0;
		for (int i = 1; i <= n; i++)
			if (a[i] != bad1)
				b[++l] = a[i];
		ok = true;
		for (int i = 1, j = l; i < j && ok; i++, --j)
			if (b[i] != b[j])
				ok = false;
		if (ok) {
			printf("YES\n");
			continue;
		}
		l = 0;
		for (int i = 1; i <= n; i++)
			if (a[i] != bad2)
				b[++l] = a[i];
		ok = true;
		for (int i = 1, j = l; i < j && ok; i++, --j)
			if (b[i] != b[j])
				ok = false;
		if (ok)
			printf("YES\n");
		else
			printf("NO\n");
	}
}