#include <cstdio>
#include <vector>
#include <algorithm>
#pragma commment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <int, ll> ill;
typedef pair <ill, int> illi;

const int Maxn = 200005;
const int Maxm = 20;

int n, m;
vector <illi> neigh[Maxn];
ll my[Maxn];
int P[Maxn];
ll D[Maxn];
int L[Maxn];
int lca[Maxn][Maxm];

void Traverse(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		illi u = neigh[v][i];
		if (u.first.first == P[v]) continue;
		P[u.first.first] = v; D[u.first.first] = u.second;
		L[u.first.first] = L[v] + 1;
		my[u.second] = u.first.second;
		lca[u.first.first][0] = v;
		Traverse(u.first.first);
	}
}

ll getNext(int a)
{
	if (P[a] != 1 && my[D[a]] == 1) {
		D[a] = getNext(P[a]); P[a] = P[P[a]];
	}
	return D[a];
}

int getLCA(int a, int b)
{
	if (L[a] < L[b]) swap(a, b);
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b])
			a = lca[a][i];
	if (a == b) return a;
	for (int i = Maxm - 1; i >= 0; i--)
		if (lca[a][i] != lca[b][i])
			a = lca[a][i], b = lca[b][i];
	return lca[a][0];
}

ll Solve(int a, int b, ll y)
{
	int to = L[getLCA(a, b)];
	vector <ll> va, vb;
	ll tot = 1;
	while (L[a] > to || L[b] > to)
		if (L[a] >= L[b]) {
			ll got = my[getNext(a)];
			if (L[P[a]] >= to)
				if (tot <= y / got) { tot *= got; va.push_back(got); }
				else return 0;
			a = P[a];
		} else {
			ll got = my[getNext(b)];
			if (L[P[b]] >= to)
				if (tot <= y / got) { tot *= got; vb.push_back(got); }
				else return 0;
			b = P[b];
		}
	for (int i = 0; i < va.size(); i++)
		y /= va[i];
	for (int i = int(vb.size()) - 1; i >= 0; i--)
		y /= vb[i];
	return y;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n - 1; i++) {
		int a, b; ll d; scanf("%d %d %I64d", &a, &b, &d);
		neigh[a].push_back(illi(ill(b, d), i));
		neigh[b].push_back(illi(ill(a, d), i));
	}
	Traverse(1);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			lca[i][j] = lca[lca[i][j - 1]][j - 1];

	while (m--) {
		int op, a, b; ll c;
		scanf("%d %d", &op, &a);
		if (op == 1) {
			scanf("%d %I64d", &b, &c);
			printf("%I64d\n", Solve(a, b, c));
		} else {
			scanf("%I64d", &c);
			my[a] = c;
		}
	}
	return 0;
}