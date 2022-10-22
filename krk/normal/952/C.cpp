#include <bits/stdc++.h>
using namespace std;

const int Maxn = 11;

int n;
int a[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (i > 0 && abs(a[i] - a[i - 1]) > 1) {
			printf("NO\n"); return 0;
		}
	}
	printf("YES\n");
	return 0;
}