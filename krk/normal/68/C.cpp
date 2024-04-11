#include <cstdio>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 8;

int n;
int L[Maxn][Maxn], H[Maxn][Maxn], A[Maxn][Maxn];
int cur;
int flow[Maxn];
int res1 = Inf, res2;

void Flow(int v, int c);

void Backtrack(int v, int u, int c)
{
	if (u > n) Flow(v + 1, c);
	else for (int i = L[v][u]; i <= H[v][u] && i <= flow[v]; i++) {
		flow[v] -= i; flow[u] += i;
		Backtrack(v, u + 1, c + (i? A[v][u] + i * i: 0));
		flow[v] += i; flow[u] -= i;
	}
}

void Flow(int v, int c)
{
	if (v == n) {
		if (flow[n] == cur && (flow[n] < res1 || flow[n] == res1 && c > res2)) { res1 = flow[n]; res2 = c; }
	} else Backtrack(v, v + 1, c);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n * (n - 1) / 2; i++) {
		int s, f, l, h, a; scanf("%d %d %d %d %d", &s, &f, &l, &h, &a);
		L[s][f] = l; H[s][f] = h; A[s][f] = a;
	}
	cur = 0;
	while (cur <= 25 && res1 == Inf) {
		flow[1] = cur;
		Flow(1, 0);
		cur++;
	}
	if (res1 == Inf) printf("-1 -1\n");
	else printf("%d %d\n", res1, res2);
	return 0;
}