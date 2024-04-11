#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;
const int Inf = 1000000000;
const int lim = 32;

int n, m;
int a[Maxn], b[Maxn];

int Gcd(int x, int y) { return x? Gcd(y % x, x): y; }

int Lcm(int x, int y) { return x / Gcd(x, y) * y; }

int Calc(int x[], int l, int r, int acc = 1)
{
	if (l == r) { x[l] = acc; return 1; }
	if (l + 1 == r) {
		Calc(x, l, l, acc * 3);
		Calc(x, r, r, acc * 4);
		return 5;
	}
	int delt = (r - l + 1) / 3;
	int agot = Calc(x, l, l + delt - 1, acc * 2);
	int bgot = Calc(x, l + delt, l + 2 * delt - 1, acc * 2);
	int cgot = Calc(x, l + 2 * delt, r, acc);
	int lcm = Lcm(agot, Lcm(bgot, cgot));
	for (int i = l; i < l + delt; i++)
		x[i] *= lcm / agot;
	for (int i = l + delt; i < l + 2 * delt; i++)
		x[i] *= lcm / bgot;
	for (int i = l + 2 * delt; i <= r; i++)
		x[i] *= lcm / cgot;
	return lcm * 3;
}

int main()
{
	scanf("%d %d", &n, &m);
	Calc(a, 0, n - 1); Calc(b, 0, m - 1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			printf("%d%c", a[i] * b[j], j + 1 < m? ' ': '\n');
	return 0;
}