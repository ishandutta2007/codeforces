#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 1000005;
const int Maxm = 4194304;

struct node {
	int l, r, f;
	ii mn;
	node(int l = 0, int r = 0, int f = 0, ii mn = ii(0, 0)): l(l), r(r), f(f), mn(mn) { }
};

int n, k;
int a[Maxn], b[Maxn];
bool was[Maxn];
node st[Maxm];
ll res;

void Union(int v)
{
	st[v].f = st[2 * v].f + st[2 * v + 1].f;
	st[v].mn = min(st[2 * v].mn, st[2 * v + 1].mn);
}

void Create(int v, int l, int r)
{
	if (l == r) st[v] = node(0, n + 1, 1, ii(a[l], l));
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		Union(v); st[v].r = n + 1;
	}
}

void addRight(int v, int l, int r, int a, int b, int val)
{
	if (l == a && r == b) st[v].r = min(st[v].r, val);
	else {
		int m = l + r >> 1;
		if (a <= m) addRight(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) addRight(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
	}
}

void addLeft(int v, int l, int r, int a, int b, int val)
{
	if (l == a && r == b) st[v].l = max(st[v].l, val);
	else {
		int m = l + r >> 1;
		if (a <= m) addLeft(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) addLeft(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
	}
}

void Erase(int v, int l, int r, int x)
{
	if (l == r) { st[v].f--; st[v].mn.first = Maxn; }
	else {
		int m = l + r >> 1;
		if (x <= m) Erase(2 * v, l, m, x);
		else Erase(2 * v + 1, m + 1, r, x);
		Union(v);
	}
}

void getFrame(int v, int l, int r, int x, int &L, int &R)
{
	L = max(L, st[v].l); R = min(R, st[v].r);
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) getFrame(2 * v, l, m, x, L, R);
		else getFrame(2 * v + 1, m + 1, r, x, L, R);
	}
}

int getW(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v].f;
	else {
		int res = 0;
		int m = l + r >> 1;
		if (a <= m) res += getW(2 * v, l, m, a, min(m, b));
		if (m + 1 <= b) res += getW(2 * v + 1, m + 1, r, max(m + 1, a), b);
		return res;
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= k; i++) {
		scanf("%d", &b[i]);
		was[b[i]] = true;
	}
	Create(1, 1, n);
	for (int i = 1; i <= n; i++) {
		ii mn = st[1].mn;
		if (was[mn.first]) { addRight(1, 1, n, 1, mn.second, mn.second); addLeft(1, 1, n, mn.second, n, mn.second); }
		else {
			int l = 0, r = n + 1;
			getFrame(1, 1, n, mn.second, l, r);
			res += getW(1, 1, n, l + 1, r - 1);
		}
		Erase(1, 1, n, mn.second);
	}
	printf("%I64d\n", res);
	return 0;
}