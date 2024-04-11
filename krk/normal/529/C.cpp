#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 2000000000;
const int Maxn = 200005;
const int Maxm = 524288;
const int Maxq = 200005;

int n, m, k, q;
int X[Maxn], Y[Maxn];
ii sR[Maxn];
int X1[Maxq], Y1[Maxq], X2[Maxq], Y2[Maxq];
ii sQ[Maxq];
int st[Maxm];
int res[Maxq];

void Create(int v, int l, int r)
{
	st[v] = -1;
	if (l < r) {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
	}
}

void Update(int v, int l, int r, int x, int val)
{
	if (l == r) st[v] = val;
	else {
		int m = l + r >> 1;
		if (x <= m) Update(2 * v, l, m, x, val);
		else Update(2 * v + 1, m + 1, r, x, val);
		st[v] = min(st[2 * v], st[2 * v + 1]);
	}
}

int Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v];
	else {
		int res = Inf;
		int m = l + r >> 1;
		if (a <= m) res = min(res, Get(2 * v, l, m, a, min(m, b)));
		if (m + 1 <= b) res = min(res, Get(2 * v + 1, m + 1, r, max(m + 1, a), b));
		return res;
	}
}

int main()
{
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &X[i], &Y[i]);
		sR[i] = ii(X[i], i);
	}
	for (int i = 0; i < q; i++) {
		scanf("%d %d %d %d", &X1[i], &Y1[i], &X2[i], &Y2[i]);
		sQ[i] = ii(X2[i], i);
	}
	
	sort(sR, sR + k); sort(sQ, sQ + q);
	Create(1, 1, m);
	int pnt = 0;
	for (int i = 0; i < q; i++) {
		while (pnt < k && sR[pnt].first <= sQ[i].first) {
			int ind = sR[pnt].second;
			Update(1, 1, m, Y[ind], X[ind]);
			pnt++;
		}
		int ind = sQ[i].second;
		int mnX = Get(1, 1, m, Y1[ind], Y2[ind]);
		if (mnX >= X1[ind]) res[ind]++;
	}
	for (int i = 0; i < k; i++)
		sR[i] = ii(Y[i], i);
	for (int i = 0; i < q; i++)
		sQ[i] = ii(Y2[i], i);

	sort(sR, sR + k); sort(sQ, sQ + q);
	Create(1, 1, n);
	pnt = 0;
	for (int i = 0; i < q; i++) {
		while (pnt < k && sR[pnt].first <= sQ[i].first) {
			int ind = sR[pnt].second;
			Update(1, 1, n, X[ind], Y[ind]);
			pnt++;
		}
		int ind = sQ[i].second;
		int mnY = Get(1, 1, n, X1[ind], X2[ind]);
		if (mnY >= Y1[ind]) res[ind]++;
	}

	for (int i = 0; i < q; i++)
		printf("%s\n", res[i]? "YES": "NO");
	return 0;
}