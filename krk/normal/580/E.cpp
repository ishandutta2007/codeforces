#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod1 = 1000000007;
const int mod2 = 1000000081;
const int arg1 = 62257177;
const int arg2 = 27947501;
const int Maxn = 100005;
const int Maxm = 524288;

struct node {
	int len;
	int h1, h2;
	int flag;
	node(int len = 0, int h1 = 0, int h2 = 0, int flag = 0): len(len), h1(h1), h2(h2), flag(flag) {}
};

int pw1[Maxn], pw2[Maxn];
int S1[Maxn], S2[Maxn];
int n, m, k;
char str[Maxn];
node st[Maxm];

node Union(const node &a, const node &b)
{
	node c;
	c.len = a.len + b.len;
	c.h1 = (ll(a.h1) * pw1[b.len] + b.h1) % mod1;
	c.h2 = (ll(a.h2) * pw2[b.len] + b.h2) % mod2;
	return c; 
}

void Down(int v)
{
	if (st[v].flag) {
		int len = st[2 * v].len;
		st[2 * v] = node(len, ll(st[v].flag) * S1[len] % mod1, ll(st[v].flag) * S2[len] % mod2, st[v].flag);
		len = st[2 * v + 1].len;
		st[2 * v + 1] = node(len, ll(st[v].flag) * S1[len] % mod1, ll(st[v].flag) * S2[len] % mod2, st[v].flag);
		st[v].flag = 0;
	}
}

void Create(int v, int l, int r)
{
	if (l == r) st[v] = node(1, str[l] - '0' + 1, str[l] - '0' + 1);
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		st[v] = Union(st[2 * v], st[2 * v + 1]);
	}
}

node Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v];
	else {
		Down(v);
		int m = l + r >> 1;
		if (b <= m) return Get(2 * v, l, m, a, b);
		if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
		return Union(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
	}
}

void Set(int v, int l, int r, int a, int b, char val)
{
	if (l == a && r == b) {
		int len = r - l + 1;
		st[v] = node(len, ll(val - '0' + 1) * S1[len] % mod1, ll(val - '0' + 1) * S2[len] % mod2, val - '0' + 1);
	} else {
		Down(v);
		int m = l + r >> 1;
		if (a <= m) Set(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) Set(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
		st[v] = Union(st[2 * v], st[2 * v + 1]);
	}
}

bool Check(int &l, int r, int d)
{
	int rl = min(d, r - (l + d) + 1);
	node n1 = Get(1, 1, n, l, l + rl - 1);
	node n2 = Get(1, 1, n, l + d, l + d + rl - 1);
	l += rl;
	return n1.h1 == n2.h1 && n1.h2 == n2.h2;
}

bool Solve(int l, int r, int d)
{
	int p = 1;
	while (p * d < r - l + 1) p *= 2;
	p /= 2;
	while (p) {
		if (!Check(l, r, p * d)) return false;
		p /= 2;
	} 
	return true;
}

int main()
{
	pw1[0] = pw2[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		pw1[i] = ll(pw1[i - 1]) * arg1 % mod1;
		pw2[i] = ll(pw2[i - 1]) * arg2 % mod2;
	}
 	S1[1] = S2[1] = 1;
 	for (int i = 2; i < Maxn; i++) {
 		S1[i] = (S1[i - 1] + pw1[i - 1]) % mod1;
 		S2[i] = (S2[i - 1] + pw2[i - 1]) % mod2;
 	}
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf(" %c", &str[i]);
	Create(1, 1, n);

	for (int i = 0; i < m + k; i++) {
		int op, l, r; scanf("%d %d %d", &op, &l, &r);
		if (op == 1) {
			char ch; scanf(" %c", &ch);
			Set(1, 1, n, l, r, ch);
		} else {
			int d; scanf("%d", &d);
			printf("%s\n", Solve(l, r, d)? "YES": "NO");
		}
	}
	return 0;
}