#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

const int Maxn = 50005;
const int Maxm = 3 * Maxn;
const int lim = 50000000;

struct event {
	int typ, x, y, y2;
	event(int typ = 0, int x = 0, int y = 0, int y2 = 0): typ(typ), x(x), y(y), y2(y2) { }
	bool operator <(const event &e) const {
		if (x != e.x) return x < e.x;
		if (typ != e.typ) return typ < e.typ;
		return y < e.y;
	}
};

int n, m;
int vx1[Maxn], vy1[Maxn], vx2[Maxn], vy2[Maxn];
int hx1[Maxn], hy1[Maxn], hx2[Maxn], hy2[Maxn];
event E[Maxm];
int elen;
int res;

bool Ok(int side)
{
	elen = 0;
	for (int i = 0; i < n; i++)
		if (2 * side <= vy2[i] - vy1[i])
			E[elen++] = event(1, vx1[i], vy1[i] + side, vy2[i] - side);
	for (int i = 0; i < m; i++)
		if (2 * side <= hx2[i] - hx1[i]) {
			E[elen++] = event(0, hx1[i] + side, hy1[i]);
			E[elen++] = event(2, hx2[i] - side, hy1[i]);
		}
	set <int> Y;
	sort(E, E + elen);
	for (int i = 0; i < elen; i++)
		if (E[i].typ == 0) Y.insert(E[i].y);
		else if (E[i].typ == 2) Y.erase(E[i].y);
		else {
			set <int>::iterator it = Y.lower_bound(E[i].y);
			if (it != Y.end() && *it <= E[i].y2) return true;
		}
	return false;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int l;
		scanf("%d %d %d", &vx1[i], &vy1[i], &l); vx2[i] = vx1[i]; vy2[i] = vy1[i] + l;
	}
	for (int i = 0; i < m; i++) {
		int l;
		scanf("%d %d %d", &hx1[i], &hy1[i], &l); hx2[i] = hx1[i] + l; hy2[i] = hy1[i];
	}
	int l = 1, r = lim;
	while (l <= r) {
		int m = l + r >> 1;
		if (Ok(m)) { res = m; l = m + 1; }
		else r = m - 1;
	}
	printf("%d\n", res);
	return 0;
}