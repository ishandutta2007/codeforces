#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <vector>

int n; 
int a[1010000];
typedef long long ll;

int Abs(int x) {return x > 0 ? x : -x;}
int x[3], y[3];
int used[1010][1010];

void coldist(int a, int b, int c, int d)
{
	for(int i = a; i <= c; i++) used[i][b] = 1;
	for(int i = c; i <= a; i++) used[i][b] = 1;
	for(int i = b; i <= d; i++) used[c][i] = 1;
	for(int i = d; i <= b; i++) used[c][i] = 1;
}

int main()
{
	int a, b, c, d, e, f; scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
	x[0] = a; x[1] = c; x[2] = e;
	y[0] = b; y[1] = d; y[2] = f;
	std::sort(x, x + 3);
	std::sort(y, y + 3);
	coldist(a, b, x[1], y[1]);
	coldist(c, d, x[1], y[1]);
	coldist(e, f, x[1], y[1]);
	int tot = 0;
	for(int i = 0; i <= 1000; i++)
		for(int j = 0; j <= 1000; j++)
		{
			if(used[i][j]) tot++;
		}
	printf("%d\n", tot);
	for(int i = 0; i <= 1000; i++)
		for(int j = 0; j <= 1000; j++)
		{
			if(used[i][j]) printf("%d %d\n", i, j);
		} 
}