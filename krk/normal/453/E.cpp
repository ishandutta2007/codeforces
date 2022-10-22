#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, ll> ii;

const int Maxn = 100005;
const int Maxm = 524288;

struct pos {
	int l, r;
	int t;
	pos(int l = 0, int r = 0, int t = 0): l(l), r(r), t(t) {}
	bool operator <(const pos &p) const {
		if (l != p.l) return l < p.l;
		if (r != p.r) return r < p.r;
		return t < p.t;
	}
};

struct col {
	int t;
	ll m, r;
	ll sum;
	col(int t = 0, ll m = 0ll, ll r = 0ll, ll sum = 0ll): t(t), m(m), r(r), sum(sum) {}
	bool operator <(const col &c) const {
		if (t != c.t) return t < c.t;
		if (m != c.m) return m < c.m;
		if (r != c.r) return r < c.r;
		return sum < c.sum;
	}
};

int n;
int s[Maxn], m[Maxn], r[Maxn];
set <pos> S;
vector <col> V[Maxm];
int q;

void Union(int v)
{
	int l = 2 * v, r = 2 * v + 1;
	int i = 0, j = 0;
	ll R = V[l].back().r + V[r].back().r;
	while (i < V[l].size() || j < V[r].size()) {
		col tk;
		if (i < V[l].size() && (j == V[r].size() || V[l][i].t < V[r][j].t)) {
			tk = V[l][i]; tk.r = i == 0? tk.r: tk.r - V[l][i - 1].r; i++;
		} else {
			tk = V[r][j]; tk.r = j == 0? tk.r: tk.r - V[r][j - 1].r; j++;
		}
		if (V[v].empty() || V[v].back().t != tk.t) V[v].push_back(tk);
		else { V[v].back().m += tk.m; V[v].back().r += tk.r; }
	}
	col lst = col(0, 0, 0, 0);
	for (int i = 0; i < V[v].size(); i++) {
		V[v][i].sum = lst.sum - ll(lst.t) * V[v][i].r + V[v][i].m + ll(V[v][i].t - lst.t) * (R - V[v][i].r - lst.r);
		V[v][i].r += lst.r;
		lst = V[v][i]; 
	}
}

void Create(int v, int L, int R)
{
	if (L == R) {
		if (r[L]) V[v].push_back(col(m[L] / r[L] + (m[L] % r[L] > 0), m[L], r[L], m[L]));
		else V[v].push_back(col(0, 0, 1, 0));
	} else {
		int m = L + R >> 1;
		Create(2 * v, L, m); Create(2 * v + 1, m + 1, R);
		Union(v);
	}
}

ll Query(int v, int l, int r, int a, int b, int t)
{
	if (l == a && r == b) {
		int ind = upper_bound(V[v].begin(), V[v].end(), col(t + 1, -1)) - V[v].begin();
		col lst = ind > 0? V[v][ind - 1]: col(0, 0, 0, 0);
		return lst.sum + ll(t - lst.t) * (V[v].back().r - lst.r);
	} else {
		ll res = 0;
		int m = l + r >> 1;
		if (a <= m) res += Query(2 * v, l, m, a, min(m, b), t);
		if (m + 1 <= b) res += Query(2 * v + 1, m + 1, r, max(m + 1, a), b, t);
		return res;
	}
}

ll Solve(int L, int R, int t)
{
	ll res = 0;
	set <pos>::iterator it = S.upper_bound(pos(L, n + 1)); it--;
	pos st = *it;
	set <pos>::iterator it2 = S.upper_bound(pos(R, n + 1)); it2--;
	pos en = *it2; it2++;
	for (; it != it2; ) {
		if (it->t == -1) res += min(s[it->l] + ll(r[it->l]) * t, ll(m[it->l]));
		else res += Query(1, 1, n, max(it->l, L), min(it->r, R), t - it->t);
		S.erase(it++);
	}
	if (st.l < L) S.insert(pos(st.l, L - 1, st.t));
	S.insert(pos(L, R, t));
	if (R < en.r) S.insert(pos(R + 1, en.r, en.t)); 
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &s[i], &m[i], &r[i]);
		S.insert(pos(i, i, -1));
	}
	Create(1, 1, n);
	scanf("%d", &q);
	while (q--) {
		int t, l, r; scanf("%d %d %d", &t, &l, &r);
		printf("%I64d\n", Solve(l, r, t));
	}
	return 0;
}