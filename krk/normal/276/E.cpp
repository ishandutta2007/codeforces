#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, q;
vector <int> neigh[Maxn];
vector <ll> RA;
vector <int> cnt, tsiz;
vector <vector <ll> > BIT, stree;
int r[Maxn], no[Maxn];

void Create(int p, int v, int R)
{
	r[v] = R; no[v] = ++cnt[R];
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u != p) Create(v, u, R);
	}
}

void addBIT(vector <ll> &B, int x, int val)
{
	for (int i = x; i > 0; i -= i & -i)
		B[i] += val;
}

void addST(vector <ll> &st, int v, int l, int r, int a, int b, int x)
{
	if (l == a && r == b) st[v] += x;
	else {
		int mid = l + r >> 1;
		if (a <= mid) addST(st, 2 * v, l, mid, a, min(mid, b), x);
		if (mid < b) addST(st, 2 * v + 1, mid + 1, r, max(mid + 1, a), b, x);
	}
}

ll getBIT(const vector <ll> &B, int x)
{
	ll res = 0ll;
	for (int i = x; i < B.size(); i += i & -i)
		res += B[i];
	return res;
}

ll getST(const vector <ll> &st, int v, int l, int r, int a)
{
	if (l == a && r == a) return st[v];
	else {
		ll res = st[v];
		int mid = l + r >> 1;
		if (a <= mid) res += getST(st, 2 * v, l, mid, a);
		else res += getST(st, 2 * v + 1, mid + 1, r, a);
		return res;
	}
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n - 1; i++) {
		int u, v; scanf("%d %d", &u, &v);
		neigh[u].push_back(v); neigh[v].push_back(u);
	}
	cnt.assign(neigh[1].size(), 0); tsiz.resize(neigh[1].size());
	BIT.resize(neigh[1].size()); stree.resize(neigh[1].size());
	for (int i = 0; i < neigh[1].size(); i++) {
		Create(1, neigh[1][i], i);
		BIT[i].assign(cnt[i] + 5, 0);
		tsiz[i] = int(pow(2.0, floor(log(double(cnt[i] + 5)) / log(2.0)) + 2.0) + 5);
		stree[i].assign(tsiz[i], 0);
	}
	RA.assign(Maxn, 0);
	while (q--) {
		int com, v; scanf("%d %d", &com, &v);
		if (com == 0) {
			int x, d; scanf("%d %d", &x, &d);
			if (v == 1) addBIT(RA, d + 1, x);
			else {
				addST(stree[r[v]], 1, 1, cnt[r[v]], max(1, no[v] - d), min(cnt[r[v]], no[v] + d), x);
				if (d >= no[v]) {
					addBIT(RA, d - no[v] + 1, x);
					addBIT(BIT[r[v]], min(cnt[r[v]], d - no[v]) + 1, -x);
				}
			}
		} else if (v == 1) printf("%I64d\n", getBIT(RA, 1));
		       else printf("%I64d\n", getBIT(RA, no[v] + 1) + getBIT(BIT[r[v]], no[v] + 1) + getST(stree[r[v]], 1, 1, cnt[r[v]], no[v]));
	}
	return 0;
}