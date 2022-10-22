#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long double ld;

const int Maxn = 100005;

int n;
int a[Maxn], b[Maxn], l[Maxn];
vector <int> neigh[Maxn];
int L[Maxn], cnt[Maxn];
ld res;

void Traverse1(int v, int p = 0)
{
	L[v] = L[p] + 1;
	cnt[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse1(u, v); cnt[v] += cnt[u];
	}
}

ld Get(int e)
{
	ld my = cnt[a[e]];
	ld his = n - cnt[a[e]];
	return l[e] * ((my * (my - 1) * his + my * his * (his - 1)) / (ld(n) * ld(n - 1) * ld(n - 2) / 6));
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &a[i], &b[i], &l[i]);
		neigh[a[i]].push_back(b[i]);
		neigh[b[i]].push_back(a[i]);
	}
	Traverse1(1);
	for (int i = 0; i < n - 1; i++) {
		if (L[a[i]] < L[b[i]]) swap(a[i], b[i]);
		res += Get(i);
	}
	int q; scanf("%d", &q);
	while (q--) {
		int e, len; scanf("%d %d", &e, &len); e--;
		res -= Get(e);
		l[e] = len;
		res += Get(e);
		printf("%.10lf\n", double(res));
	}
	return 0;
}