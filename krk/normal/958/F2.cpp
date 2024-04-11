#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Inf = 1000000000;

int n, m;
int a[Maxn];
int nd[Maxn];
int cur[Maxn];
int sat;
int res = Inf;

void Add(int x)
{
	if (++cur[x] == nd[x]) sat++;
}

void Rem(int x)
{
	if (cur[x]-- == nd[x]) sat--;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int sum = 0;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &nd[i]);
		sum += nd[i];
		if (nd[i] == 0) sat++;
	}
	int l = 1;
	for (int i = 1; i <= n; i++) {
		Add(a[i]);
		while (sat >= m) {
			res = min(res, i - l + 1 - sum);
			Rem(a[l]); l++;
		}
	}
	printf("%d\n", res >= Inf? -1: res);
	return 0;
}