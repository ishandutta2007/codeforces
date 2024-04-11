#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n, m;
int d[Maxn];
int a[Maxn];
int ex[Maxn];

bool Ok(int n)
{
	for (int i = 1; i <= m; i++)
		ex[i] = -1;
	for (int i = 0; i < n; i++) if (d[i] != 0)
		ex[d[i]] = i;
	for (int i = 1; i <= m; i++)
		if (ex[i] == -1) return false;
	int cur = 0;
	for (int i = 0; i < n; i++)
		if (d[i] == 0) cur++;
		else if (ex[d[i]] == i)
				if (a[d[i]] <= cur) cur -= a[d[i]];
				else return false;
			else cur++;
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &d[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &a[i]);
	int l = 1, r = n;
	int res = -1;
	while (l <= r) {
		int m = l + r >> 1;
		if (Ok(m)) { res = m; r = m - 1; }
		else l = m + 1;
	}
	printf("%d\n", res);
	return 0;
}