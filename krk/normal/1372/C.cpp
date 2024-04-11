#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		int l = 1;
		while (l <= n && a[l] == l) l++;
		if (l > n) { printf("0\n"); continue; }
		int r = n;
		while (r > 0 && a[r] == r) r--;
		int found = 0;
		for (int i = l; i <= r; i++)
			if (a[i] == i) found = 1;
		printf("%d\n", 1 + found);
	}
    return 0;
}