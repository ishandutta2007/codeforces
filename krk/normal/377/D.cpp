#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int lim = 300000;
const int Maxm = 2097152;

struct triple {
	int a, b, c;
	triple(int a = 0, int b = 0, int c = 0): a(a), b(b), c(c) {}
	bool operator <(const triple &t) const {
		if (a != t.a) return a < t.a;
		if (b != t.b) return b < t.b;
		return c < t.c;
	}
};

int n;
int l[Maxn], v[Maxn], r[Maxn];
triple srt[2 * Maxn];
ii st[Maxm];
int toch[Maxm];
int res;
int bl, br;

void Down(int v)
{
	st[2 * v].first += toch[v]; toch[2 * v] += toch[v];
	st[2 * v + 1].first += toch[v]; toch[2 * v + 1] += toch[v];
	toch[v] = 0;
}

void Union(int v)
{
	st[v] = st[2 * v].first >= st[2 * v + 1].first? st[2 * v]: st[2 * v + 1];
}

void Create(int v, int l, int r)
{
	if (l == r) st[v] = ii(0, l);
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		Union(v);
	}
}

void Update(int v, int l, int r, int a, int b, int delt)
{
	if (l == a && r == b) { st[v].first += delt; toch[v] += delt; }
	else {
		Down(v);
		int m = l + r >> 1;
		if (a <= m) Update(2 * v, l, m, a, min(b, m), delt);
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(a, m + 1), b, delt);
		Union(v);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &l[i], &v[i], &r[i]);
		srt[2 * i] = triple(l[i], 0, i); srt[2 * i + 1] = triple(v[i], 1, i);
	}
	sort(srt, srt + 2 * n);
	Create(1, 1, lim);
	for (int i = 0; i < 2 * n; i++)
		if (srt[i].b == 0) {
			Update(1, 1, lim, v[srt[i].c], r[srt[i].c], 1);
			if (st[1].first > res) { res = st[1].first; bl = srt[i].a; br = st[1].second; }
		} else Update(1, 1, lim, v[srt[i].c], r[srt[i].c], -1);
	printf("%d\n", res);
	bool pr = false;
	for (int i = 0; i < n; i++)
		if (l[i] <= bl && br <= r[i] && bl <= v[i] && v[i] <= br) {
			printf("%s%d", pr? " ": "", i + 1);
			pr = true;
		}
	printf("\n");
	return 0;
}