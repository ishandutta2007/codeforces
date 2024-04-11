#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n, d;
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &d);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		bool ok = true;
		for (int i = 0; i < n && ok; i++)
			ok = a[i] <= d || a[0] + a[1] <= d;
		printf("%s\n", ok? "YES": "NO");
	}
    return 0;
}