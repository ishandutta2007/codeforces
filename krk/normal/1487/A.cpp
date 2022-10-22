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
		int pnt = 0;
		while (pnt < n && a[0] == a[pnt]) pnt++;
		printf("%d\n", n - pnt);
	}
    return 0;
}