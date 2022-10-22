#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const ll Inf = 1000000000000000000ll;
const int Maxn = 100005;
const int Maxm = 524288;
const int Maxp = 50;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
string let = "LDRU";

struct event {
	int typ;
	int a1, a2, b1, b2;
	int id;
	event(int typ = 0, int a1 = 0, int a2 = 0, int b1 = 0, int b2 = 0, int id = 0): typ(typ), a1(a1), a2(a2), b1(b1), b2(b2), id(id) {}
	bool operator <(const event &e) const {
		if (a1 != e.a1) return a1 < e.a1;
		if (typ != e.typ) return typ < e.typ;
		if (b1 != e.b1) return b1 < e.b1;
		return b2 < e.b2; 
	}
};

struct parent {
	int dr, lft, arr;
	parent(int dr = 0, int lft = 0, int arr = 0): dr(dr), lft(lft), arr(arr) {}
};

int n, b;
int X0[Maxn], Y0[Maxn], X1[Maxn], Y1[Maxn];
int my[Maxn];
int q;
int X[Maxn], Y[Maxn];
char dr[Maxn];
ll tim[Maxn];
vector <event> E[4]; // L, D, R, U
ii st[Maxm];
ii ares[Maxn], qres[Maxn];
ii cango[Maxn][Maxp];
ll cost[Maxn][Maxp];
int arr[Maxn][Maxp];
parent P[Maxn][Maxp];

void Clear(int v, int a, int b)
{
	st[v] = ii(-1, 0);
	if (a < b) {
		int m = a + b >> 1;
		Clear(2 * v, a, m); Clear(2 * v + 1, m + 1, b);
	}
}

void Insert(int v, int l, int r, int a, int b, ii p)
{
	if (a == l && b == r) st[v] = p;
	else {
		int m = l + r >> 1;
		if (a <= m) Insert(2 * v, l, m, a, min(m, b), p);
		if (m + 1 <= b) Insert(2 * v + 1, m + 1, r, max(m + 1, a), b, p);
	}
}

ii Get(int v, int l, int r, int x)
{
	ii best = st[v];
	if (l < r) {
		ii got;
		int m = l + r >> 1;
		if (x <= m) got = Get(2 * v, l, m, x);
		else got = Get(2 * v + 1, m + 1, r, x);
		best = ii(best.second, best.first) >= ii(got.second, got.first)? best: got;
	}
	return best;
}

void Solve(int side, vector <event> &E)
{
	sort(E.begin(), E.end());
	Clear(1, 0, b);
	for (int i = 0; i < E.size(); i++)
		if (E[i].typ == 0) {
			if (my[E[i].id] == side) { ares[E[i].id] = Get(1, 0, b, E[i].b1); ares[E[i].id].second = E[i].a1 - ares[E[i].id].second; }
			Insert(1, 0, b, E[i].b1, E[i].b2, ii(E[i].id, E[i].a2));
		} else { qres[E[i].id] = Get(1, 0, b, E[i].b1); qres[E[i].id].second = max(E[i].a1 - qres[E[i].id].second, 0); }
}

ii calcDist(int arrow, ii c, ll need, int rec)
{
	if (arrow == -1) return c;
	ll togo = min(need, ll(abs(X1[arrow] - c.first) + abs(Y1[arrow] - c.second))); need -= togo;
	c = ii(c.first + togo * dx[my[arrow]], c.second + togo * dy[my[arrow]]);
	if (need) {
		while (1ll << rec > need) rec--;
		c = cango[arrow][rec]; parent tmp = P[arrow][rec]; need -= 1ll << rec;
		togo = min(need, ll(tmp.lft)); need -= togo;
		c = ii(c.first + togo * dx[tmp.dr], c.second + togo * dy[tmp.dr]);
		if (need) c = calcDist(tmp.arr, c, need, rec);
	}
	return c;
}

int main()
{
	scanf("%d %d", &n, &b);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &X0[i], &Y0[i], &X1[i], &Y1[i]);
		if (X0[i] == Y0[i] && X1[i] == Y1[i]) { n--; i--; continue; }
		if (X0[i] > X1[i]) my[i] = 0;
		else if (Y0[i] > Y1[i]) my[i] = 1;
		else if (X0[i] < X1[i]) my[i] = 2;
		else my[i] = 3;
		E[0].push_back(event(0, min(X0[i], X1[i]), max(X0[i], X1[i]), min(Y0[i], Y1[i]), max(Y0[i], Y1[i]), i));
		E[1].push_back(event(0, min(Y0[i], Y1[i]), max(Y0[i], Y1[i]), min(X0[i], X1[i]), max(X0[i], X1[i]), i));
		E[2].push_back(event(0, b - max(X0[i], X1[i]), b - min(X0[i], X1[i]), min(Y0[i], Y1[i]), max(Y0[i], Y1[i]), i));
		E[3].push_back(event(0, b - max(Y0[i], Y1[i]), b - min(Y0[i], Y1[i]), min(X0[i], X1[i]), max(X0[i], X1[i]), i));
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d %d %c %I64d", &X[i], &Y[i], &dr[i], &tim[i]);
		if (dr[i] == 'L') E[0].push_back(event(1, X[i], X1[i], Y[i], Y[i], i));
		else if (dr[i] == 'D') E[1].push_back(event(1, Y[i], Y[i], X[i], X[i], i));
		else if (dr[i] == 'R') E[2].push_back(event(1, b - X[i], b - X[i], Y[i], Y[i], i));
		else if (dr[i] == 'U') E[3].push_back(event(1, b - Y[i], b - Y[i], X[i], X[i], i));
	}
	for (int i = 0; i < 4; i++)
		Solve(i, E[i]);
	for (int i = 0; i < n; i++) {
		cango[i][0] = ii(X1[i] + ares[i].second * dx[my[i]], Y1[i] + ares[i].second * dy[my[i]]);
		cost[i][0] = ares[i].second;
		arr[i][0] = ares[i].first;
	}
	for (int j = 1; j < Maxp; j++)
		for (int i = 0; i < n; i++)
			if (arr[i][j - 1] == -1) { cango[i][j] = cango[i][j - 1]; cost[i][j] = cost[i][j - 1]; arr[i][j] = arr[i][j - 1]; }
			else {
				ii c = cango[i][j - 1];
				cango[i][j] = cango[arr[i][j - 1]][j - 1];
				cost[i][j] = min(Inf, cost[i][j - 1] + abs(c.first - X1[arr[i][j - 1]]) + abs(c.second - Y1[arr[i][j - 1]]) + cost[arr[i][j - 1]][j - 1]);
				arr[i][j] = arr[arr[i][j - 1]][j - 1];
			}
	for (int i = 0; i < q; i++) {
		ll need = tim[i];
		ll togo = min(need, ll(qres[i].second)); need -= togo;
		int d = let.find(dr[i]);
		ii c = ii(X[i] + togo * dx[d], Y[i] + togo * dy[d]);
		int arrow = qres[i].first;
		int rec = Maxp - 1;
		while (need) {
			if (arrow == -1) break;
			togo = min(need, ll(abs(c.first - X1[arrow]) + abs(c.second - Y1[arrow]))); need -= togo;
			c = ii(c.first + togo * dx[my[arrow]], c.second + togo * dy[my[arrow]]);
			if (!need) break;
			while (rec >= 0 && cost[arrow][rec] > need) rec--;
			if (rec < 0) break;
			need -= cost[arrow][rec]; c = cango[arrow][rec]; arrow = arr[arrow][rec];
		}
		if (need && arrow != -1) c = ii(c.first + need * dx[my[arrow]], c.second + need * dy[my[arrow]]);
		printf("%d %d\n", c.first, c.second);
	}
	return 0;
}