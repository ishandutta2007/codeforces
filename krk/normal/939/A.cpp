#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;

int n;
int a[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		if (a[a[a[i]]] == i) { printf("YES\n"); return 0; }
	printf("NO\n");
	return 0;
}