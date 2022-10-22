#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int mn = 1;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			if (a[i] < a[mn]) mn = i;
		}
		printf("%d\n", n - 1);
		for (int i = 1; i <= n; i++) if (i != mn)
			printf("%d %d %d %d\n", mn, i, a[mn], a[mn] + abs(i - mn));
	}
    return 0;
}