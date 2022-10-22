#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;

int T;
int n;
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		bool ok = false;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			for (int j = 0; j + 1 < i; j++)
				if (a[j] == a[i]) ok = true;
		}
		printf("%s\n", ok? "YES": "NO");
	}
    return 0;
}