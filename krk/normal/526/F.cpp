#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 300005;
const int Maxm = 2097152;

struct node {
	int mn, cnt;
	int flag;
	node(int mn = 0, int cnt = 0, int flag = 0): mn(mn), cnt(cnt), flag(flag) {}
};

int n;
int seq[Maxn];
node st[Maxm];
int Smx[Maxn], Smxl;
int Smn[Maxn], Smnl;
ll res;

void Union(node &a, const node &b, const node &c)
{
	a.mn = min(b.mn, c.mn);
	a.cnt = 0;
	if (a.mn == b.mn) a.cnt += b.cnt;
	if (a.mn == c.mn) a.cnt += c.cnt;
}

void Down(int v)
{
	if (st[v].flag) {
		st[2 * v].mn += st[v].flag; st[2 * v].flag += st[v].flag;
		st[2 * v + 1].mn += st[v].flag; st[2 * v + 1].flag += st[v].flag;
		st[v].flag = 0;
	}
}

void Create(int v, int l, int r)
{
	if (l == r) st[v] = node(l, 1);
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		Union(st[v], st[2 * v], st[2 * v + 1]);
	} 
}

void Update(int v, int l, int r, int a, int b, int val)
{
	if (l == a && r == b) { st[v].mn += val; st[v].flag += val; }
	else {
		Down(v);
		int m = l + r >> 1;
		if (a <= m) Update(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
		Union(st[v], st[2 * v], st[2 * v + 1]);
	}
}

node getNode(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v];
	else {
		int m = l + r >> 1;
		if (b <= m) return getNode(2 * v, l, m, a, b);
		if (m + 1 <= a) return getNode(2 * v + 1, m + 1, r, a, b);
		node res; Union(res, getNode(2 * v, l, m, a, m), getNode(2 * v + 1, m + 1, r, m + 1, b));
		return res;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int r, c; scanf("%d %d", &r, &c);
		seq[r] = c;
	}
	Create(1, 1, n);
	Smnl = Smxl = 1;
	for (int i = 1; i <= n; i++) {
		while (Smxl > 1 && seq[i] > seq[Smx[Smxl - 1]]) {
			Smxl--;
			int l = Smx[Smxl - 1] + 1, r = Smx[Smxl];
			Update(1, 1, n, l, r, seq[i] - seq[Smx[Smxl]]);
		}
		Smx[Smxl++] = i;

		while (Smnl > 1 && seq[i] < seq[Smn[Smnl - 1]]) {
			Smnl--;
			int l = Smn[Smnl - 1] + 1, r = Smn[Smnl];
			Update(1, 1, n, l, r, seq[Smn[Smnl]] - seq[i]);
		}
		Smn[Smnl++] = i;

		node got = getNode(1, 1, n, 1, i);
		if (got.mn == i) res += got.cnt;
	}
	printf("%I64d\n", res);
	return 0;
}