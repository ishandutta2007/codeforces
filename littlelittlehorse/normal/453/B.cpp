#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

int f[101][1111][11], pre[101][1111][11], what[101][1111][11], n, a[101], c[101], w[101], e;
bool b[61];

int gcd(int a, int b){
	if (!b) return a;
	return gcd(b, a % b);
}

int main(){
	//freopen("b.in", "r", stdin);
	//freopen("b.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	memset(b, false, sizeof(b));
	b[1] = true;
	for (int i = 2; i <= 60; i++)
		for (int j = i + i; j <= 60; j += i) b[j] = true;
	e = 0;
	for (int i = 31; i <= 60; i++)
		if (!b[i]) w[++e] = i;
	memset(f, 127, sizeof(f));
	f[0][0][0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 1 << 10; j++)
			for (int l = 0; l <= e; l++)
			if (f[i - 1][j][l] < 1 << 30)
				for (int k = 1; k <= 60; k++)
				{
					int status = 0;
					for (int r = 0; r < 10; r++)
						if (!(k % prime[r])) status |= 1 << r;
					if (l < e && f[i - 1][j][l] + abs(a[i] - w[l + 1]) < f[i][j][l + 1])
					{
						f[i][j][l + 1] = f[i - 1][j][l] + abs(a[i] - w[l + 1]);
						what[i][j][l + 1] = w[l + 1];
						pre[i][j][l + 1] = j;
					}
					if (status & j) continue;
					if (k > 30 && !b[k]) continue;
					int value = f[i - 1][j][l] + abs(a[i] - k);
					//if ((status | j) == 0) printf("%d %d %d %d\n", i, status | j, k, f[i][status | j]);
					if (value < f[i][status | j][l])
						f[i][status | j][l] = value, what[i][status | j][l] = k, pre[i][status | j][l] = j;
					//if ((status | j) == 0) printf("%d %d %d %d %d\n", i, status | j, k, f[i][status | j], what[i][status | j]);
				}
	int ans = 1 << 30, pos = 0, pos1 = 0;
	//for (int i = 0; i < 1 << 10; i++) printf("%d\n", f[1][i]);
	for (int j = 0; j < 1 << 10; j++) 
		for (int l = 0; l <= e; l++)
		if (f[n][j][l] < ans) ans = min(ans, f[n][j][l]), pos = j, pos1 = l;
	//printf("%d\n", ans);
	int cnt = 0;
	for (int i = n; i; --i) 
	{
		c[++cnt] = what[i][pos][pos1], pos = pre[i][pos][pos1];
		if (c[cnt] > 30 && !b[c[cnt]]) --pos1;
	}
	for (int i = n; i >= 1; i--)
	{
		printf("%d", c[i]);
		if (i != 1) printf(" ");
	}
	printf("\n");
}