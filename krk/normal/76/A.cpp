#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 9000000000000000000ll;
const int Maxn = 205;
const int Maxm = 50005;

struct edge {
	int x, y, g, s;
	edge(int x = 0, int y = 0, int g = 0, int s = 0): x(x), y(y), g(g), s(s) { }
};

int n, m;
int g, s;
edge E[Maxm];
int c, p[Maxn], siz[Maxn];
vector <int> neigh[Maxn];
bool taken[Maxn];
map <int, int> M;
ll res = Inf;

bool Less(const edge &a, const edge &b)
{
	return a.g < b.g;
}

int getPar(int x) { return p[x] == x? x: p[x] = getPar(p[x]); }

void unionSet(int a, int b)
{
	int para = getPar(a), parb = getPar(b);
	if (siz[para] >= siz[parb]) { siz[para] += siz[parb]; p[parb] = para; }
	else { siz[parb] += siz[para]; p[para] = parb; }
	c--;
}

int getMax(int a, int b)
{
	if (taken[a] || a == b) return -1;
	taken[a] = true;
	for (int i = 0; i < neigh[a].size(); i++) {
		int e = neigh[a][i];
		int u = E[e].x == a? E[e].y: E[e].x;
		if (u == b) return e;
		int res = getMax(u, b);
		if (res != -1) return E[e].s >= E[res].s? e: res;
	}
	return -1;
}

void Add(int a, int b, int c)
{
	neigh[a].push_back(c); neigh[b].push_back(c);
	M[E[c].s]++;
}

void Rem(int a, int b, int c)
{
	for (int i = 0; i < neigh[a].size(); i++)
		if (neigh[a][i] == c) { neigh[a].erase(neigh[a].begin() + i); break; }
	for (int i = 0; i < neigh[b].size(); i++)
		if (neigh[b][i] == c) { neigh[b].erase(neigh[b].begin() + i); break; }
	if (--M[E[c].s] == 0) M.erase(E[c].s);
}

int main()
{
	scanf("%d %d", &n, &m);
	scanf("%d %d", &g, &s);
	for (int i = 0; i < m; i++) {
		int xi, yi, gi, si; scanf("%d %d %d %d", &xi, &yi, &gi, &si);
		E[i] = edge(xi, yi, gi, si);
	}
	sort(E, E + m, Less);
	for (int i = 1; i <= n; i++) p[i] = i, siz[i] = 1;
	c = n;
	for (int i = 0; i < m; i++) {
		int a = E[i].x, b = E[i].y;
		if (getPar(a) != getPar(b)) { unionSet(a, b); Add(a, b, i); }
		else {
			fill(taken, taken + n + 1, false);
			int mx = getMax(a, b);
			if (mx != -1 && E[i].s < E[mx].s) { Add(a, b, i); Rem(E[mx].x, E[mx].y, mx); }
		}
		if (c == 1) res = min(res, ll(g) * ll(E[i].g) + ll(s) * ll(M.rbegin()->first));
	}
	printf("%I64d\n", res == Inf? -1ll: res);
	return 0;
}