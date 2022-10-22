#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

const int Maxn = 100005;
const ll Inf = 1000000000000000000ll;

int n, m, q;
int c[Maxn];
vector <int> neigh[Maxn];
vector <int> inCity[Maxn];
int cur, lef[Maxn], rig[Maxn], cnt[Maxn];
int my[Maxn], L[Maxn], P[Maxn], ind[Maxn];
vector <int> seq[Maxn];
ll BIT[Maxn];

struct segtree {
	vector <llll> st;
	vector <ll> add;
	vector <ll> BIT;
	int n;
	segtree(int gn = 1) {
		n = gn;
		int m = 1;
		while (m <= 4 * n) m *= 2;
		st.resize(m); add.resize(m);
		BIT.resize(n, 0);
	}
	void Create(int v, int l, int r, const vector <int> &V)
	{
		if (l == r)
			if (inCity[V[l]].empty()) { st[v] = llll(Inf, -1); add[v] = Inf; }
			else { st[v] = llll(inCity[V[l]].back(), V[l]); add[v] = inCity[V[l]].back(); }
		else {
			int m = l + r >> 1;
			Create(2 * v, l, m, V); Create(2 * v + 1, m + 1, r, V);
			st[v] = min(st[2 * v], st[2 * v + 1]);
			add[v] = 0;
		}
	}
	void Create(const vector <int> &V) {
		Create(1, 0, n - 1, V);
	}
	llll getBest(int v, int l, int r, int a, int b)
	{
		if (l == a && r == b) return st[v];
		else {
			int m = l + r >> 1;
			llll res;
			if (b <= m) res = getBest(2 * v, l, m, a, b);
			else if (m + 1 <= a) res = getBest(2 * v + 1, m + 1, r, a, b);
			else res = min(getBest(2 * v, l, m, a, m), getBest(2 * v + 1, m + 1, r, m + 1, b));
			res.first += add[v];
			return res;
		}
	}
	llll getBest(int a, int b) { 
		llll best = getBest(1, 0, n - 1, a, b);
		if (best.second != -1) best.first += getBIT(ind[best.second]);
		return best;
	}
	void Remove(int v, int l, int r, int city)
	{
		if (l == r) {
			add[v] -= inCity[city].back(); inCity[city].pop_back();
			if (inCity[city].empty()) { st[v] = llll(Inf, -1); add[v] = Inf; }
			else { add[v] += inCity[city].back(); st[v] = llll(add[v], city); }
		} else {
			int m = l + r >> 1;
			if (ind[city] <= m) Remove(2 * v, l, m, city);
			else Remove(2 * v + 1, m + 1, r, city);
			st[v] = min(st[2 * v], st[2 * v + 1]);
			st[v].first += add[v];
		}
	}
	void Remove(int city) { Remove(1, 0, n - 1, city); }
	void Update(int v, int l, int r, int a, int b, int val)
	{
		if (l == a && r == b) { st[v].first += val; add[v] += val; }
		else {
			int m = l + r >> 1;
			if (a <= m) Update(2 * v, l, m, a, min(m, b), val);
			if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
			st[v] = min(st[2 * v], st[2 * v + 1]);
			st[v].first += add[v];
		}
	}
	void Update(int ind, int val) {
		Update(1, 0, n - 1, ind, n - 1, val);
		ind++;
		for (int i = ind; i <= n; i += i & -i)
			BIT[i - 1] -= val;
	}
	ll getBIT(int ind) {
		ll res = 0ll;
		ind++;
		for (int i = ind; i > 0; i -= i & -i)
			res += BIT[i - 1];
		return res;
	}
};


segtree S[Maxn];

void Traverse1(int v)
{
	lef[v] = ++cur;
	cnt[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (P[v] == u) continue;
		P[u] = v; L[u] = L[v] + 1;
		Traverse1(u);
		cnt[v] += cnt[u];
	}
	rig[v] = cur;
}

void Traverse2(int v, int myp)
{
	my[v] = myp; ind[v] = seq[myp].size();
	seq[myp].push_back(v);
	bool was = false;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (P[v] == u) continue;
		if (cnt[u] > cnt[v] / 2) { Traverse2(u, myp); was = true; }
		else Traverse2(u, u);
	}
	if (!was) {
		S[myp] = segtree(seq[myp].size());
		S[myp].Create(seq[myp]);
	}
}

void Insert(int x, ll val)
{
	for (int i = x; i <= n; i += i & -i)
		BIT[i] += val;
}

ll Get(int x)
{
	ll res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

llll getBest(int v, int u)
{
	llll got = llll(Inf, -1);
	while (my[v] != my[u])
		if (L[my[v]] >= L[my[u]]) {
			llll cand = S[my[v]].getBest(0, ind[v]);
			if (cand.second != -1)
				cand.first += Get(lef[cand.second]);
			got = min(got, cand);
			v = P[my[v]];
		} else {
			llll cand = S[my[u]].getBest(0, ind[u]);
			if (cand.second != -1)
				cand.first += Get(lef[cand.second]);
			got = min(got, cand);
			u = P[my[u]];
		}
	int l = min(ind[v], ind[u]), r = max(ind[v], ind[u]);
	llll cand = S[my[v]].getBest(l, r);
	if (cand.second != -1)
		cand.first += Get(lef[cand.second]);
	got = min(got, cand);
	return got;
}

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	for (int i = 1; i <= m; i++) {
		int c; scanf("%d", &c);
		inCity[c].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		sort(inCity[i].rbegin(), inCity[i].rend());
	Traverse1(1);
	Traverse2(1, 1);
	while (q--) {
		int t; scanf("%d", &t);
		if (t == 1) {
			int v, u, k; scanf("%d %d %d", &v, &u, &k);
			vector <int> inv;
			while (k--) {
				llll b = getBest(v, u);
				if (b.second == -1) break;
				inv.push_back(inCity[b.second].back());
				S[my[b.second]].Remove(b.second);
			}
			printf("%d", inv.size());
			for (int i = 0; i < inv.size(); i++)
				printf(" %d", inv[i]);
			printf("\n");
		} else {
			int v, k; scanf("%d %d", &v, &k);
			Insert(lef[v], k); Insert(rig[v] + 1, -k);
			S[my[v]].Update(ind[v], k);
		}
	}
	return 0;
}