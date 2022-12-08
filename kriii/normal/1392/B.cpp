#include <stdio.h>
#include <algorithm>
using namespace std;

int n, a[200200];

void go()
{
	int u = *max_element(a, a + n);
	for (int i = 0; i < n; i++) a[i] = u - a[i];
}

int main()
{
	int t; scanf ("%d", &t); while (t--){
		long long k;
		scanf ("%d %lld", &n, &k);
		for (int i = 0; i < n; i++) scanf ("%d", &a[i]);
		if (k >= 4) k = (k - 4) % 2 + 4;
		while (k--) go();
		for (int i = 0; i < n; i++) printf ("%d%c", a[i], i + 1 < n ? ' ' : '\n');
	}

	return 0;
}