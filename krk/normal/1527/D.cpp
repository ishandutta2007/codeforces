#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxm = 21;

int T;
int n;
vector <int> neigh[Maxn];
int L[Maxn], P[Maxn][Maxm];
int cnt[Maxn];
ll res[Maxn];

void Traverse(int v)
{
	cnt[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == P[v][0]) continue;
		P[u][0] = v; L[u] = L[v] + 1;
		Traverse(u);
		cnt[v] += cnt[u];
	}
}

bool Reach(int a, int b)
{
	if (L[a] < L[b]) return false;
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b])
			a = P[a][i];
	return a == b;
}

int getLast(int a, int b)
{
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) > L[b])
			a = P[a][i];
	return a;
}

ll getAll(int a, int b)
{
	if (b == 1) {
		int lsta = getLast(a, b);
		return ll(cnt[a]) * (cnt[b] - cnt[lsta]);
	} else return ll(cnt[a]) * cnt[b];
}

int getLCA(int a, int b)
{
	if (L[a] < L[b]) swap(a, b);
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b])
			a = P[a][i];
	if (a == b) return a;
	for (int i = Maxm - 1; i >= 0; i--)
		if (P[a][i] != P[b][i])
			a = P[a][i], b = P[b][i];
	return P[a][0];
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			neigh[i].clear();
		for (int i = 0; i < n - 1; i++) {
			int a, b; scanf("%d %d", &a, &b);
			a++; b++;
			neigh[a].push_back(b);
			neigh[b].push_back(a);
		}
		Traverse(1);
		for (int j = 1; j < Maxm; j++)
			for (int i = 1; i <= n; i++)
				P[i][j] = P[P[i][j - 1]][j - 1];
		fill(res, res + n + 1, 0ll);
		res[0] = ll(n) * (n - 1) / 2;
		res[1] = 0;
		ll cur = 1;
		for (int i = 0; i < neigh[1].size(); i++) {
			int v = neigh[1][i];
			res[1] += cur * cnt[v];
			cur += cnt[v];
		}
		int A = 1, B = 1;
		for (int i = 2; i <= n; i++)
			if (Reach(A, i) || Reach(B, i)) res[i] = getAll(A, B);
			else if (Reach(i, A)) {
				A = i;
				res[i] = getAll(A, B);
			} else if (getLCA(A, i) != 1) break; 
			else if (Reach(i, B)) {
				B = i;
				res[i] = getAll(A, B);
			} else break;
		for (int i = 0; i < n; i++)
			res[i] -= res[i + 1];
		for (int i = 0; i <= n; i++)
			printf("%I64d%c", res[i], i + 1 <= n? ' ': '\n');
	}
    return 0;
}