#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 500005;
const int Maxm = 1000005;

int n, k;
int a[Maxn];
int cnt[Maxm], tot;
int best = -1, bi, bj;

void Add(int x)
{
	if (cnt[x]++ == 0) tot++;
}

void Rem(int x)
{
	if (--cnt[x] == 0) tot--;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int r = 1;
	for (int i = 1; i <= n; i++) {
		while (r <= n && tot <= k) Add(a[r++]);
		if (tot > k) Rem(a[--r]);
		if (r - i > best) { best = r - i; bi = i; bj = r - 1; }
		Rem(a[i]);
	}
	printf("%d %d\n", bi, bj);
	return 0;
}