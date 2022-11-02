#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, len[101], f[10001], g[111][111], a[101], v[101][101], m;
 
int main(){
	scanf("%d%d", &n, &m);
	memset(v, 0, sizeof(v));
	for (int k = 1; k <= n; k++)
	{
		scanf("%d", &len[k]); int cnt = 0;
		for (int j = 1; j <= len[k]; j++) scanf("%d", &a[j]), cnt += a[j];
		g[1][len[k]] = 0;
		memset(g, 0, sizeof(g));
		for (int i = len[k] - 1; i >= 1; --i)
			for (int j = 1; j <= len[k] - i; j++)
				g[j + 1][j + i] = max(g[j + 1][j + i], g[j][j + i] + a[j]),
				g[j][j + i - 1] = max(g[j][j + i - 1], g[j][j + i] + a[j + i]);
		v[k][len[k]] = cnt;
		for (int i = 1; i <= len[k]; i++)
			for (int j = i; j <= len[k]; j++) 
				v[k][len[k] - (j - i) - 1] = max(v[k][len[k] - (j - i) - 1], g[i][j]);
	}
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 0; --j)
			for (int k = 0; k <= len[i] && k + j <= m; k++)
				f[j + k] = max(f[j + k], f[j] + v[i][k]);
	printf("%d\n", f[m]);
}