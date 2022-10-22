#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 150005;
const int Maxm = 1048576;

int n, len, h;
int b[Maxn], a[Maxn];
int has[Maxm], miss[Maxm];
int res;

void Create(int v, int l, int r)
{
	if (l == r) miss[v] = l;
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		miss[v] = max(miss[2 * v], miss[2 * v + 1]);
	}
}

void Insert(int v, int l, int r, int x)
{
	if (l == x && r == x) { has[v]++; miss[v]--; }
	else {
		int m = l + r >> 1;
		if (x <= m) Insert(2 * v, l, m, x);
		else Insert(2 * v + 1, m + 1, r, x);
		has[v] = has[2 * v] + has[2 * v + 1];
		miss[v] = max(miss[2 * v], miss[2 * v + 1] - has[2 * v]);
	}
}

void Erase(int v, int l, int r, int x)
{
	if (l == x && r == x) { has[v]--; miss[v]++; }
	else {
		int m = l + r >> 1;
		if (x <= m) Erase(2 * v, l, m, x);
		else Erase(2 * v + 1, m + 1, r, x);
		has[v] = has[2 * v] + has[2 * v + 1];
		miss[v] = max(miss[2 * v], miss[2 * v + 1] - has[2 * v]);
	}
}

int main()
{
	scanf("%d %d %d", &n, &len, &h);
	for (int i = 1; i <= len; i++)
		scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(b + 1, b + len + 1);
	Create(1, 1, len);
	for (int i = 1; i <= len; i++) {
		int ind = lower_bound(b + 1, b + len + 1, h - a[i]) - b;
		if (ind <= len) Insert(1, 1, len, ind);
	}
	res += miss[1] <= 0;
	for (int i = len + 1; i <= n; i++) {
		int ind = lower_bound(b + 1, b + len + 1, h - a[i]) - b;
		if (ind <= len) Insert(1, 1, len, ind);
		ind = lower_bound(b + 1, b + len + 1, h - a[i - len]) - b;
		if (ind <= len) Erase(1, 1, len, ind);
		res += miss[1] <= 0;
	}
	printf("%d\n", res);
	return 0;
}