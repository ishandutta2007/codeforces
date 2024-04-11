#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 95542721;
const int Maxp = 48;
const int Maxn = 100005;
const int Maxm = 524288;

int n;
int a[Maxn];
int q;
int sum[Maxm][Maxp], cur[Maxm];

void toLower(int v)
{
	cur[2 * v] = (cur[2 * v] + cur[v]) % Maxp;
	cur[2 * v + 1] = (cur[2 * v + 1] + cur[v]) % Maxp;
	cur[v] = 0;
}

void Union(int v)
{
	for (int i = 0; i < Maxp; i++)
		sum[v][i] = (sum[2 * v][(cur[2 * v] + i) % Maxp] + sum[2 * v + 1][(cur[2 * v + 1] + i) % Maxp]) % mod;
}

void Create(int v, int l, int r)
{
	if (l == r) {
		sum[v][0] = a[l];
		for (int i = 1; i < Maxp; i++)
			sum[v][i] = ll(sum[v][i - 1]) * ll(sum[v][i - 1]) % ll(mod) * ll(sum[v][i - 1]) % ll(mod);
	} else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		Union(v);
	}
}

void Update(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) cur[v] = (cur[v] + 1) % Maxp;
	else {
		toLower(v);
		int m = l + r >> 1;
		if (a <= m) Update(2 * v, l, m, a, min(m, b));
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b);
		Union(v);
	}
}

int Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return sum[v][cur[v]];
	else {
		toLower(v);
		int res = 0;
		int m = l + r >> 1;
		if (a <= m) res = (res + Get(2 * v, l, m, a, min(m, b))) % mod;
		if (m + 1 <= b) res = (res + Get(2 * v + 1, m + 1, r, max(m + 1, a), b)) % mod;
		Union(v);
		return res;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	Create(1, 1, n);
	scanf("%d", &q);
	while (q--) {
		int t, l, r; scanf("%d %d %d", &t, &l, &r);
		if (t == 1) printf("%d\n", Get(1, 1, n, l, r));
		else Update(1, 1, n, l, r);
	}
	return 0;
}