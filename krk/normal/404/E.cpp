#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxn = 1000005;
const int Maxm = 4194304;

struct node {
	int mx, ind;
	int mn, flag;
	node(int mx = 0, int ind = 0, int mn = 0, int flag = 0): mx(mx), ind(ind), mn(mn), flag(flag) { }
};

char s[Maxn];
int slen;
int a[Maxn];
node st[Maxm];
int res;

void Down(int v)
{
	st[2 * v].mx -= st[v].flag; st[2 * v].mn -= st[v].flag; st[2 * v].flag += st[v].flag;
	st[2 * v + 1].mx -= st[v].flag; st[2 * v + 1].mn -= st[v].flag; st[2 * v + 1].flag += st[v].flag;
	st[v].flag = 0;
}

void Union(int v)
{
	if (st[2 * v].mx >= st[2 * v + 1].mx) { st[v].mx = st[2 * v].mx; st[v].ind = st[2 * v].ind; }
	else { st[v].mx = st[2 * v + 1].mx; st[v].ind = st[2 * v + 1].ind; }
	st[v].mn = min(st[2 * v].mn, st[2 * v + 1].mn);
}

void Create(int v, int l, int r)
{
	if (l == r) st[v] = node(a[l], l, a[l]);
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		Union(v);
	}
}

void Substract(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) { st[v].mx--; st[v].mn--; st[v].flag++; }
	else {
		Down(v);
		int m = l + r >> 1;
		if (a <= m) Substract(2 * v, l, m, a, min(m, b));
		if (m + 1 <= b) Substract(2 * v + 1, m + 1, r, max(m + 1, a), b);
		Union(v);
	}
}

int main()
{
	scanf("%s", s); slen = strlen(s);
	if (slen == 1) { printf("1\n"); return 0; }
	int ka, kb;
	if (s[slen - 1] == 'L') { ka = -1; kb = 1; }
	else { ka = 1; kb = -1; }
	int cur = 0;
	for (int i = 0; i < slen; i++) {
		if (s[i] == 'L') cur += ka;
		else cur += kb;
		a[i] = cur;
	}
	Create(1, 0, slen - 2);
	if (a[slen - 1] < st[1].mn && a[slen - 1] < 0) { printf("1\n"); return 0; }
	while (st[1].mx > 0) {
		Substract(1, 0, slen - 2, st[1].ind, slen - 2); a[slen - 1]--;
		res += a[slen - 1] < st[1].mn && a[slen - 1] < 0;
	}
	printf("%d\n", res);
	return 0;
}