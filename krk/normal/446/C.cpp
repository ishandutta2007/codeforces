#include <cstdio>
#include <set>
using namespace std;

typedef long long ll;

const int mod = 1000000009;
const int Maxd = 2;
const int Maxn = 300005;
const int Maxm = 2097152;

struct matrix {
	int m[Maxd][Maxd];
	matrix(int diag = 0) {
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++)
				m[i][j] = diag * (i == j);
	}
	matrix operator *(const matrix &b) const {
		matrix c;
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++)
				for (int l = 0; l < Maxd; l++)
					c.m[i][j] = (c.m[i][j] + ll(m[i][l]) * b.m[l][j] % mod) % mod;
		return c;
	}
	matrix operator +(const matrix &b) const {
		matrix c;
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++)
				c.m[i][j] = (m[i][j] + b.m[i][j]) % mod;
		return c;
	}
	bool Null() const {
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++)
				if (m[i][j]) return false;
		return true;
	}
};

matrix M[Maxn], S[Maxn];
int n, m;
int a[Maxn];
int sum[Maxm];
matrix st[Maxm];

void Create(int v, int l, int r)
{
	if (l == r) sum[v] = a[l];
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		sum[v] = (sum[2 * v] + sum[2 * v + 1]) % mod;
	}
}

void addSt(int v, int siz, const matrix &b) 
{ 
	st[v] = st[v] + b; 
	sum[v] = (sum[v] + (b * S[siz - 1]).m[0][1]) % mod; 
}

void Down(int v, int l, int m, int r)
{
	if (!st[v].Null()) {
		addSt(2 * v, m - l + 1, st[v]);
		addSt(2 * v + 1, r - m, st[v] * M[m + 1 - l]);
		st[v] = matrix(0);
	}
}

int Sum(int v, int siz) { return ((st[v] * S[siz - 1]).m[0][1] + sum[v]) % mod; }

void Union(int v) { sum[v] = (sum[2 * v] + sum[2 * v + 1]) % mod; }

void Update(int v, int l, int r, int a, int b, const matrix &f)
{
	if (l == a && r == b) addSt(v, r - l + 1, f);
	else {
		int m = l + r >> 1;
		Down(v, l, m, r);
		if (b <= m) Update(2 * v, l, m, a, b, f);
		else if (m + 1 <= a) Update(2 * v + 1, m + 1, r, a, b, f);
		else {
			Update(2 * v, l, m, a, m, f);
			Update(2 * v + 1, m + 1, r, m + 1, b, f * M[m + 1 - a]);
		}
		Union(v);
	}
}

int Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return sum[v];
	else {
		int m = l + r >> 1;
		Down(v, l, m, r);
		int cur = 0;
		if (a <= m) cur = (cur + Get(2 * v, l, m, a, min(m, b))) % mod;
		if (m + 1 <= b) cur = (cur + Get(2 * v + 1, m + 1, r, max(m + 1, a), b)) % mod;
		Union(v);
		return cur;
	}
}

int main()
{
	M[0] = matrix(1); S[0] = M[0];
	M[1].m[0][0] = 1; M[1].m[0][1] = 1;
	M[1].m[1][0] = 1; M[1].m[1][1] = 0;
	S[1] = S[0] + M[1];
	for (int i = 2; i < Maxn; i++) {
		M[i] = M[i - 1] * M[1];
		S[i] = S[i - 1] + M[i];
	}
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	Create(1, 1, n);
	int t, l, r;
	while (m--) {
		scanf("%d %d %d", &t, &l, &r);
		if (t == 1) Update(1, 1, n, l, r, M[1]);
		else printf("%d\n", Get(1, 1, n, l, r));
	}
	return 0;
}