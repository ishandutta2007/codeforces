#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxm = 1048576;
const int Inf = 2000000000;

int n;
int X1[Maxn], Y1[Maxn], X2[Maxn], Y2[Maxn];
vector <int> unY;
int has[Maxm];
int cur, p[Maxm], siz[Maxm];
ll len[Maxm];
set <int> XS;
ll res;

int Stat(int x, int ind)
{
	if (X1[ind] == X2[ind]) return 2;
	return x == X1[ind]? 1: 3;
}

struct event {
	int x, id;
	event(int x = 0, int id = 0): x(x), id(id) {}
	bool operator <(const event &e) const {
		if (x != e.x) return x < e.x;
		int h1 = Stat(x, id), h2 = Stat(e.x, e.id);
		if (h1 != h2) return h1 < h2;
		return Y1[id] < Y1[e.id];
	}
};

event E[Maxm];
int elen;

struct interval {
	int l, r, id;
	interval(int l = 0, int r = 0, int id = 0): l(l), r(r), id(id) {}
	bool operator <(const interval &b) const {
		if (l != b.l) return l < b.l;
		return r < b.r;
	}
};

set <interval> S;

int Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return has[v];
	else {
		int res = 0;
		int m = l + r >> 1;
		if (a <= m) res += Get(2 * v, l, m, a, min(m, b));
		if (m + 1 <= b) res += Get(2 * v + 1, m + 1, r, max(m + 1, a), b);
		return res;
	}
}

void Update(int v, int l, int r, int x, int delt)
{
	if (l == r) has[v] += delt;
	else {
		int m = l + r >> 1;
		if (x <= m) Update(2 * v, l, m, x, delt);
		if (m + 1 <= x) Update(2 * v + 1, m + 1, r, x, delt);
		has[v] = has[2 * v] + has[2 * v + 1];
	}
}

int getPar(int x) { return p[x] == x? x: p[x] = getPar(p[x]); }

bool unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return false;
	if (siz[a] >= siz[b]) { p[b] = a; siz[a] += siz[b]; len[a] += len[b]; }
	else { p[a] = b; siz[b] += siz[a]; len[b] += len[a]; }
	return true;
}

int getNext(int y)
{
	return *XS.lower_bound(y);
}

int getPrev(int y)
{
	set <int>::iterator it = XS.upper_bound(y);
	it--;
	return *it;
}

void Insert(int id)
{
	set <interval>::iterator it = S.lower_bound(interval(Y1[id], Inf));
	if (it != S.begin()) {
		it--;
		if (it->l <= Y1[id] && Y1[id] <= it->r) {
			interval inter = *it; S.erase(it);
			S.insert(interval(inter.l, getPrev(Y1[id] - 1), inter.id));
			S.insert(interval(getNext(Y1[id] + 1), inter.r, inter.id));
		}
	}
	p[cur] = cur; siz[cur] = 1; len[cur] = X2[id] - X1[id];
	S.insert(interval(Y1[id], Y1[id], cur)); cur++;
	Update(1, 0, unY.size() - 1, Y1[id], 1); XS.insert(Y1[id]);
}

bool Catch(const interval &inter, int id)
{
	int l = max(Y1[id], inter.l), r = min(Y2[id], inter.r);
	if (l > r) return false;
	return Get(1, 0, unY.size() - 1, l, r) > 0;
}

void Connect(int id)
{
	int cross = Get(1, 0, unY.size() - 1, Y1[id], Y2[id]);
	if (cross == 0)
		res = max(res, ll(unY[Y2[id]] - unY[Y1[id]]));
	else {
		set <interval>::iterator it = S.lower_bound(interval(Y1[id], Inf));
		if (it != S.begin()) it--;
		while (!Catch(*it, id)) it++;
		int dist = 1;
		interval inter = *it; S.erase(it++);
		while (it != S.end() && Catch(*it, id)) {
			if (unionSet(inter.id, it->id)) dist++;
			inter.r = it->r; S.erase(it++);
		}
		len[getPar(inter.id)] += unY[Y2[id]] - unY[Y1[id]] - (cross - 1) + dist - 1;
		S.insert(inter);
	}
}

void Erase(int id)
{
	set <interval>::iterator it = S.lower_bound(interval(Y1[id], Inf)); it--;
	Update(1, 0, unY.size() - 1, Y1[id], -1); XS.erase(Y1[id]);
	if (Get(1, 0, unY.size() - 1, it->l, it->r) == 0) {
		res = max(res, len[getPar(it->id)]);
		S.erase(it);
	} else if (Y1[id] == it->l) {
		interval inter = interval(getNext(it->l + 1), it->r, it->id);
		S.erase(it); S.insert(inter);
	} else if (Y1[id] == it->r) {
		interval inter = interval(it->l, getPrev(it->r - 1), it->id);
		S.erase(it); S.insert(inter);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &X1[i], &Y1[i], &X2[i], &Y2[i]);
		unY.push_back(Y1[i]); unY.push_back(Y2[i]);
	}
	sort(unY.begin(), unY.end()); unY.erase(unique(unY.begin(), unY.end()), unY.end());
	for (int i = 0; i < n; i++) {
		Y1[i] = lower_bound(unY.begin(), unY.end(), Y1[i]) - unY.begin();
		Y2[i] = lower_bound(unY.begin(), unY.end(), Y2[i]) - unY.begin();
		if (Y1[i] == Y2[i]) { E[elen++] = event(X1[i], i); E[elen++] = event(X2[i], i); }
		else E[elen++] = event(X1[i], i);
	}
	sort(E, E + elen);
	for (int i = 0; i < elen; i++) {
		int st = Stat(E[i].x, E[i].id);
		if (st == 1) Insert(E[i].id);
		else if (st == 2) Connect(E[i].id);
		else Erase(E[i].id);
	}
	printf("%I64d\n", res);
	return 0;
}