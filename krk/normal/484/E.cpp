#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 2097152;

struct pos {
	int lef, rig, tot;
	pos(int lef = 0, int rig = 0, int tot = 0): 
		lef(lef), rig(rig), tot(tot) {}
};

int n;
ii a[Maxn];
int cur, L[Maxm], R[Maxm];
pos st[Maxm];
int S[Maxn];
int m;

int newNode() { return ++cur; }

void Create(int v, int l, int r)
{
	st[v] = pos(0, 0, 0);
	if (l < r) {
		int m = l + r >> 1;
		L[v] = newNode(); R[v] = newNode();
		Create(L[v], l, m); Create(R[v], m + 1, r);
	}
}

pos Union(const pos &a, const pos &b, int lsiz, int rsiz)
{
	return pos(a.lef == lsiz? a.lef + b.lef: a.lef, 
			   b.rig == rsiz? b.rig + a.rig: b.rig, 
			   max(a.rig + b.lef, max(a.tot, b.tot)));
}

void Union(int v, int lsiz, int rsiz)
{
	st[v] = Union(st[L[v]], st[R[v]], lsiz, rsiz);
}

void Add(int v, int oldv, int l, int r, int x)
{
	if (l == r) st[v] = pos(1, 1, 1);
	else {
		int m = l + r >> 1;
		if (x <= m) {
			L[v] = newNode(); R[v] = R[oldv];
			Add(L[v], L[oldv], l, m, x);
		} else {
			L[v] = L[oldv]; R[v] = newNode();
			Add(R[v], R[oldv], m + 1, r, x);
		}
		Union(v, m - l + 1, r - m);
	}
}

pos getNode(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v];
	else {
		int m = l + r >> 1;
		if (b <= m) return getNode(L[v], l, m, a, b);
		if (m + 1 <= a) return getNode(R[v], m + 1, r, a, b);
		return Union(getNode(L[v], l, m, a, m), getNode(R[v], m + 1, r, m + 1, b), m - a + 1, b - m);
	}
}

bool Less(const ii &a, const ii &b) 
{ 
	if (a.first != b.first) return a.first > b.first;
	return a.second < b.second;
}

int main()
{
	scanf("%d", &n);
	S[0] = newNode();
	Create(S[0], 1, n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a + 1, a + n + 1, Less);
	for (int i = 1; i <= n; i++) {
		S[i] = newNode();
		Add(S[i], S[i - 1], 1, n, a[i].second);
	}
	scanf("%d", &m);
	while (m--) {
		int l, r, w; scanf("%d %d %d", &l, &r, &w);
		int L = 1, R = n;
		int res = -1;
		pos got;
		while (L <= R) {
			int m = L + R >> 1;
			got = getNode(S[m], 1, n, l, r);
			if (got.tot >= w) { res = a[m].first; R = m - 1; }
			else L = m + 1;
		}
		printf("%d\n", res);
	}
	return 0;
}