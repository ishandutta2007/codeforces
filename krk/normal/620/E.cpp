#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 400005;
const int Maxm = 2097152;
const int Maxl = 60;

int n, m;
int col[Maxn];
vector <int> neigh[Maxn];
int cur, L[Maxn], R[Maxn];
int has[Maxn];
char fl[Maxm], len[Maxm];
char st[Maxm][Maxl];

void Traverse(int v, int p = 0)
{
	L[v] = ++cur; has[L[v]] = col[v];
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (p == u) continue;
		Traverse(u, v);
	}
	R[v] = cur;
}

void Union(char a[], char alen, char b[], char blen, char c[], char &clen)
{
	clen = 0;
	int i = 0, j = 0;
	while (i < alen || j < blen)
		if (i < alen && (j == blen || a[i] < b[j])) c[clen++] = a[i++];
		else if (j < blen && (i == alen || b[j] < a[i])) c[clen++] = b[j++];
		else { c[clen++] = a[i]; i++; j++; }
}

void downOn(int v, char c)
{
	fl[v] = c; len[v] = 1; st[v][0] = c;
}

void Down(int v)
{
	if (fl[v]) {
		downOn(2 * v, fl[v]); downOn(2 * v + 1, fl[v]);
		fl[v] = 0;
	}
}

void Create(int v, int l, int r)
{
	if (l == r) st[v][len[v]++] = has[l];
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		Union(st[2 * v], len[2 * v], st[2 * v + 1], len[2 * v + 1], st[v], len[v]);
	}
}

void Update(int v, int l, int r, int a, int b, char c)
{
	if (l == a && r == b) downOn(v, c);
	else {
		Down(v);
		int m = l + r >> 1;
		if (a <= m) Update(2 * v, l, m, a, min(m, b), c);
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, c);
		Union(st[2 * v], len[2 * v], st[2 * v + 1], len[2 * v + 1], st[v], len[v]);
	}
}

void Get(int v, int l, int r, int a, int b, char tmp[], char &tlen)
{
	if (l == a && r == b) {
		tlen = len[v];
		for (int i = 0; i < len[v]; i++)
			tmp[i] = st[v][i];
	} else {
		Down(v);
		int m = l + r >> 1;
		if (b <= m) Get(2 * v, l, m, a, b, tmp, tlen);
		else if (m + 1 <= a) Get(2 * v + 1, m + 1, r, a, b, tmp, tlen);
		else {
			char tmp1[Maxl], tlen1, tmp2[Maxl], tlen2;
			Get(2 * v, l, m, a, m, tmp1, tlen1);
			Get(2 * v + 1, m + 1, r, m + 1, b, tmp2, tlen2);
			Union(tmp1, tlen1, tmp2, tlen2, tmp, tlen); 
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &col[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1);
	Create(1, 1, n);
	while (m--) {
		int t, v, c;
		scanf("%d %d", &t, &v);
		if (t == 1) {
			scanf("%d", &c);
			Update(1, 1, n, L[v], R[v], c);
		} else {
			char tmp[Maxl], tlen;
			Get(1, 1, n, L[v], R[v], tmp, tlen);
			printf("%d\n", int(tlen));
		}
	}
	return 0;
}