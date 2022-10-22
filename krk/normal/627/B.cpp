#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 200005;

int n, k, a, b, q;
int d[Maxn];
int A[Maxn], B[Maxn];

void InsertA(int x, int val)
{
	for (int i = x; i > 0; i -= i & -i)
		A[i] += val;
}

int GetA(int x)
{
	int res = 0;
	for (int i = x; i <= n; i += i & -i)
		res += A[i];
	return res;
}

void InsertB(int x, int val)
{
	for (int i = x; i <= n; i += i & -i)
		B[i] += val;
}

int GetB(int x)
{
	int res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res += B[i];
	return res;
}

int main()
{
	scanf("%d %d %d %d %d", &n, &k, &a, &b, &q);
	while (q--) {
		int typ; scanf("%d", &typ);
		if (typ == 1) {
			int di, ai; scanf("%d %d", &di, &ai);
			int old = d[di];
			d[di] += ai;
			InsertA(di, min(d[di], a) - min(old, a));
			InsertB(di, min(d[di], b) - min(old, b));
		} else {
			int p; scanf("%d", &p);
			int res = GetB(p - 1) + GetA(p + k);
			printf("%d\n", res);
		}
	}
	return 0;
}