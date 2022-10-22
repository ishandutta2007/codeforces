#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		a[i] %= 2;
		if (a[i] == 1)
			if (a[i + 1] <= 0) { printf("NO\n"); return 0; }
			else a[i + 1]--;
	}
	printf("YES\n");
	return 0;
}