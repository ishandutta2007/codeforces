#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxn = 100005;
const int Maxm = 524288;
const int Maxl = 26;

struct node {
	int freq[Maxl];
	int flag;
	node() { fill(freq, freq + Maxl, 0); flag = 0; }
};

int n, q;
char str[Maxn];
node st[Maxm];

void Create(int v, int l, int r)
{
	if (l == r) st[v].freq[str[l] - 'a']++;
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		for (int i = 0; i < Maxl; i++)
			st[v].freq[i] = st[2 * v].freq[i] + st[2 * v + 1].freq[i];
	}
}

void getI(int to[], int from[], int len)
{
	for (int i = 0; i < Maxl; i++) {
		int tk = min(from[i], len);
		from[i] -= tk; len -= tk;
		to[i] = tk;
	}
}

void getD(int to[], int from[], int len)
{
	for (int i = Maxl - 1; i >= 0; i--) {
		int tk = min(from[i], len);
		from[i] -= tk; len -= tk;
		to[i] = tk;
	}
}

void Down(int v, int len1, int len2)
{
	if (!st[v].flag) return;
	if (st[v].flag == 1) { getI(st[2 * v].freq, st[v].freq, len1); getI(st[2 * v + 1].freq, st[v].freq, len2); }
	else { getD(st[2 * v].freq, st[v].freq, len1); getD(st[2 * v + 1].freq, st[v].freq, len2); }
	st[2 * v].flag = st[v].flag; st[2 * v + 1].flag = st[v].flag;
	st[v].flag = 0;
}

void Get(int v, int l, int r, int a, int b, int res[])
{
	if (l == a && r == b)
		for (int i = 0; i < Maxl; i++)
			res[i] += st[v].freq[i];
	else {
		int m = l + r >> 1;
		Down(v, m - l + 1, r - m);
		if (a <= m) Get(2 * v, l, m, a, min(m, b), res);
		if (m + 1 <= b) Get(2 * v + 1, m + 1, r, max(m + 1, a), b, res);
	}
}

void Update(int v, int l, int r, int a, int b, int upd[], int k)
{
	if (l == a && r == b)
		if (k == 1) {
			getI(st[v].freq, upd, r - l + 1); st[v].flag = 1;
		} else {
			getD(st[v].freq, upd, r - l + 1); st[v].flag = -1;
		}
	else {
		int m = l + r >> 1;
		Down(v, m - l + 1, r - m);
		if (a <= m) Update(2 * v, l, m, a, min(m, b), upd, k);
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, upd, k);
		for (int i = 0; i < Maxl; i++)
			st[v].freq[i] = st[2 * v].freq[i] + st[2 * v + 1].freq[i];
	}
}

void Print(int v, int l, int r)
{
	if (l == r) {
		int i = 0;
		while (!st[v].freq[i]) i++;
		printf("%c", 'a' + i);
	} else {
		int m = l + r >> 1;
		Down(v, m - l + 1, r - m);
		Print(2 * v, l, m); Print(2 * v + 1, m + 1, r);
	}
}

int main()
{
	scanf("%d %d", &n, &q);
	scanf("%s", str + 1);
	Create(1, 1, n);
	int tmp[Maxl];
	while (q--) {
		int i, j, k; scanf("%d %d %d", &i, &j, &k);
		fill(tmp, tmp + Maxl, 0);
		Get(1, 1, n, i, j, tmp);
		Update(1, 1, n, i, j, tmp, k);
	}
	Print(1, 1, n); printf("\n");
	return 0;
}