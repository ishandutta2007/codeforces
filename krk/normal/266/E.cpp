#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 100005;
const int Maxm = 524288;
const int Maxk = 6;

int C[Maxk][Maxk];
int pw[Maxk][Maxn], sum[Maxk][Maxn];
int n, m;
int a[Maxn];
int flag[Maxk][Maxm], st[Maxk][Maxm];

void Create(int t, int v, int l, int r)
{
	if (l == r) st[t][v] = ll(a[l]) * ll(pw[t][l]) % ll(mod);
	else {
		int m = l + r >> 1;
		Create(t, 2 * v, l, m); Create(t, 2 * v + 1, m + 1, r);
		st[t][v] = (st[t][2 * v] + st[t][2 * v + 1]) % mod;
	}
	flag[t][v] = -1;
}

void Calc(int t, int v, int l, int r)
{
	st[t][v] = ll(flag[t][v]) * ll(sum[t][r] - sum[t][l - 1] + mod) % ll(mod);
}

void Down(int t, int v, int l, int r)
{
	if (l < r) {
		int m = l + r >> 1;
		flag[t][2 * v] = flag[t][2 * v + 1] = flag[t][v];
		Calc(t, 2 * v, l, m); Calc(t, 2 * v + 1, m + 1, r);
	}
	flag[t][v] = -1; 
}

void Update(int t, int v, int l, int r, int a, int b, int x)
{
	if (l == a && r == b) { flag[t][v] = x; Calc(t, v, l, r); }
	else {
		if (flag[t][v] != -1) Down(t, v, l, r);
		int m = l + r >> 1;
		if (a <= m) Update(t, 2 * v, l, m, a, min(m, b), x);
		if (m + 1 <= b) Update(t, 2 * v + 1, m + 1, r, max(m + 1, a), b, x);
		st[t][v] = (st[t][2 * v] + st[t][2 * v + 1]) % mod;
	}
}

int Get(int t, int v, int l, int r, int a, int b)
{
	if (l == a && b == r) return st[t][v];
	else {
		if (flag[t][v] != -1) Down(t, v, l, r);
		int res = 0;
		int m = l + r >> 1;
		if (a <= m) res = (res + Get(t, 2 * v, l, m, a, min(m, b))) % mod;
		if (m + 1 <= b) res = (res + Get(t, 2 * v + 1, m + 1, r, max(m + 1, a), b)) % mod;
		return res;
	}
}

int getRes(int l, int r, int k)
{
	int cur = Get(k, 1, 1, n, l, r);
	int mult = (1 - l + mod) % mod;
	int has = 1;
	for (int i = 1; i <= k; i++) {
		has = ll(has) * ll(mult) % ll(mod);
		cur = (cur + ll(C[k][i]) * ll(has) % ll(mod) * ll(Get(k - i, 1, 1, n, l, r)) % ll(mod)) % mod;
	}
	return cur;
}

int main()
{
	for (int i = 0; i < Maxk; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	fill(pw[0], pw[0] + Maxn, 1);
	for (int j = 1; j < Maxn; j++)
		sum[0][j] = (sum[0][j - 1] + pw[0][j]) % mod;
	for (int i = 1; i < Maxk; i++)
		for (int j = 1; j < Maxn; j++) {
			pw[i][j] = ll(pw[i - 1][j]) * ll(j) % ll(mod);
			sum[i][j] = (sum[i][j - 1] + pw[i][j]) % mod;
		}
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < Maxk; i++) Create(i, 1, 1, n);
	while (m--) {
		char com; int l, r, x; scanf(" %c %d %d %d", &com, &l, &r, &x);
		if (com == '=')
			for (int i = 0; i < Maxk; i++) Update(i, 1, 1, n, l, r, x);
		else printf("%d\n", getRes(l, r, x));
	}
	return 0;
}