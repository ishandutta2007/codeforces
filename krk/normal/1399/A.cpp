#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		bool ok = true;
		for (int i = 0; i + 1 < n && ok; i++)
			ok = abs(a[i] - a[i + 1]) <= 1;
		printf("%s\n", ok? "YES": "NO");
	}
    return 0;
}