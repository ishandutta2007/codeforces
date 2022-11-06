#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>

int n, m;
int a[510][510], b[510][510];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) scanf("%d", &b[i][j]);	

	for(int i = 1; i < n; i++)
	{
		int sum = 0;
		for(int j = 1; j <= m; j++) if(a[i][j] != b[i][j]) sum++;
		if(sum & 1) return 0 * puts("No");
		for(int j = 1; j <= m; j++) if(a[i][j] != b[i][j]) a[i + 1][j] ^= 1;
	}
	for(int j = 1; j <= m; j++) if(a[n][j] != b[n][j]) return 0 * puts("No");
	puts("Yes");
}