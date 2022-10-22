#include <cstdio>
using namespace std;

const int Maxn = 1 << 17;
const int Maxm = 1048576;

int n, m;
int a[Maxn];
bool door[Maxm];
int res[Maxm];

void Create(int v, int l, int r)
{
	if (l == r) { door[v] = false; res[v] = a[l]; }
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		door[v] = !door[2 * v];
		if (door[v]) res[v] = res[2 * v] | res[2 * v + 1];
		else res[v] = res[2 * v] ^ res[2 * v + 1];
	}
}

void Insert(int v, int l, int r, int x, int val)
{
	if (l == r) res[v] = val;
	else {
		int m = l + r >> 1;
		if (x <= m) Insert(2 * v, l, m, x, val);
		else Insert(2 * v + 1, m + 1, r, x, val);
		if (door[v]) res[v] = res[2 * v] | res[2 * v + 1];
		else res[v] = res[2 * v] ^ res[2 * v + 1];
	}
}

int main()
{
	scanf("%d %d", &n, &m); n = 1 << n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	Create(1, 0, n - 1);
	while (m--) {
		int p, b; scanf("%d %d", &p, &b);
		Insert(1, 0, n - 1, p - 1, b);
		printf("%d\n", res[1]);
	}
	return 0;
}