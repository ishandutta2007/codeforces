#include <bits/stdc++.h>
using namespace std;

const int Maxn = 52;

int T;
int n;
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		bool ok = true;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			if (a[i] != i) ok = false;
		}
		if (ok) printf("0\n");
		else if (a[1] == 1 || a[n] == n) printf("1\n");
		else if (a[1] == n && a[n] == 1) printf("3\n");
			 else printf("2\n");
	}
    return 0;
}