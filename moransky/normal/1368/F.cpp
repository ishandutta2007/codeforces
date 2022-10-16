#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
#define MAXN 200100
#define ll long long
int n, m, u, d[MAXN];
bool st[MAXN];
int main()
{
	scanf("%d",&n);
	m = sqrt(n);
	for (int i = 1; i <= 10000; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (!st[j] && (j % m != 1)) {
				st[j] = 1;
				d[++cnt] = j;
				
				if (cnt == m) break;
			}
		}
		printf("%d ", cnt);
		for (int j = 1; j <= cnt; j++) printf("%d ", d[j]);
			printf("\n");
		fflush(stdout);
		scanf("%d",&u);
		for (int j = 0; j < m; j++) {
			st[u] = 0;
			u++;
			if (u == n + 1) u = 1;
		}
	}
	
	printf("0\n");
	fflush(stdout);
	
	return 0;
}