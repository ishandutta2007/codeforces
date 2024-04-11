#include <iostream>
#include <cstring>
#include <cstdio>
#define T 440
#define MN 201000

int fa[MN / T + 5][110];
int w[MN / T + 5][110];
int a[MN], c[MN / T + 5][110], n;

int Find(int *fa, int x) {return fa[x] == x ? x : fa[x] = Find(fa, fa[x]);}

int rebuild(int x)
{
	int l = x * T, r = std::min((x + 1) * T - 1, n - 1);
	for(int i = l; i <= r; i++) a[i] = c[x][Find(fa[x], a[i])];
	for(int i = 1; i <= 100; i++) fa[x][i] = i, w[x][i] = i, c[x][i] = i;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i <= (n - 1) / T; i++)
		for(int j = 1; j <= 100; j++) fa[i][j] = j, w[i][j] = j, c[i][j] = j;
	int q; scanf("%d", &q);
	while(q--)
	{
		int l, r, x, y; scanf("%d%d%d%d", &l, &r, &x, &y);
		if(x == y) continue;
		l--; r--;
		int lb = l / T, rb = r / T;
		if(lb == rb)
		{
			rebuild(lb);
			for(int i = l; i <= r; i++) if(a[i] == x) a[i] = y;
		}
		else
		{
			rebuild(lb);
			for(int i = l; i <= (lb + 1) * T - 1; i++) if(a[i] == x) a[i] = y;
			rebuild(rb);
			for(int i = rb * T; i <= r; i++) if(a[i] == x) a[i] = y;
			for(int i = lb + 1; i < rb; i++)
			{
				int A = w[i][x], B = w[i][y];
				if(!A) continue;
				if(!B) c[i][A] = y, w[i][x] = 0, w[i][y] = A;
				else fa[i][A] = B, w[i][x] = 0;
			}
		}
	}
	for(int i = 0; i <= (n - 1) / T; i++) rebuild(i);
	for(int i = 0; i < n; i++) printf("%d ", a[i]);
}