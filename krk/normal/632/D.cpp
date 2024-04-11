#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 1000005;

int n, m;
int a[Maxn];
int f[Maxn];
int hm[Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] <= m) f[a[i]]++;
	}
	for (int i = 1; i <= m; i++)
		for (int j = i; j <= m; j += i)
			hm[j] += f[i];
	int bi = 1;
	for (int j = 1; j <= m; j++)
		if (hm[j] > hm[bi]) bi = j;
	printf("%d %d\n", bi, hm[bi]);
	bool was = false;
	for (int i = 1; i <= n; i++)
		if (bi % a[i] == 0) {
			if (was) printf(" ");
			was = true;
			printf("%d", i);
		}
	printf("\n");
	return 0;
}