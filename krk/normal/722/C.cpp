#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int a[Maxn];
int perm[Maxn];
ll res[Maxn];
int par[Maxn], siz[Maxn];
bool ex[Maxn];
ll sum[Maxn];
ll mx;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void Merge(int a, int b)
{
	siz[a] += siz[b]; sum[a] += sum[b]; par[b] = a; 
	mx = max(mx, sum[a]);
}

void unionSet(int a, int b)
{
	if (a < 1 || a > n || b < 1 || b > n || !ex[a] || !ex[b]) return;
	a = getPar(a), b = getPar(b);
	if (a == b) return;
	if (siz[a] >= siz[b]) Merge(a, b);
	else Merge(b, a);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &perm[i]);
	for (int i = 1; i <= n; i++) {
		par[i] = i; siz[i] = 1; sum[i] = a[i];
	}
	for (int i = n; i >= 1; i--) {
		res[i] = mx;
		ex[perm[i]] = true;
		mx = max(mx, sum[perm[i]]);
		unionSet(perm[i], perm[i] - 1);
		unionSet(perm[i], perm[i] + 1);
	}
	for (int i = 1; i <= n; i++)
		printf("%I64d\n", res[i]);
	return 0;
}