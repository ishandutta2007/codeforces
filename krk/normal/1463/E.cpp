#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int n, k;
int p[Maxn];
int par[Maxn], siz[Maxn];
int X[Maxn], Y[Maxn];
int fir[Maxn];
int inmy[Maxn];
int nxt[Maxn], to[Maxn];
set <int> neigh[Maxn];
int tk[Maxn];
vector <int> seq;
vector <int> res;
int inres[Maxn];
int root;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return false;
	if (siz[a] < siz[b]) swap(a, b);
	siz[a] += siz[b]; par[b] = a;
	return true;
}

bool Solve(int v)
{
	if (tk[v] == 2) return true;
	if (tk[v] == 1) return false;
	tk[v] = 1;
	for (auto it: neigh[v])
		if (!Solve(it)) return false;
	seq.push_back(v);
	tk[v] = 2;
	return true;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		if (!p[i]) root = i;
		par[i] = i; siz[i] = 1;
	}
	for (int i = 0; i < k; i++) {
		int x, y; scanf("%d %d", &x, &y);
		X[i] = x; Y[i] = y;
		if (!unionSet(x, y)) { printf("0\n"); return 0; }
		nxt[x] = y;
		to[y] = x;
	}
	for (int i = 1; i <= n; i++) if (!to[i]) {
		fir[getPar(i)] = i;
		int num = i;
		int val = 0;
		inmy[num] = val;
		while (nxt[num] != 0) {
			num = nxt[num];
			val++;
			inmy[num] = val;
		}
	}
	for (int i = 1; i <= n; i++) if (p[i] != 0) {
		int a = getPar(p[i]);
		int b = getPar(i);
		if (a != b) neigh[a].insert(b);
		else if (inmy[p[i]] > inmy[i]) { printf("0\n"); return 0; }
	}
	if (Solve(getPar(root))) {
		for (int i = int(seq.size()) - 1; i >= 0; i--) {
			int v = fir[seq[i]];
			res.push_back(v);
			while (nxt[v] != 0) {
				v = nxt[v];
				res.push_back(v);
			}
		}
		for (int i = 0; i < res.size(); i++)
			printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	} else printf("0\n");
    return 0;
}