#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;
const int Inf = 1000000000;

set <int> P;
int n, m;
int a[Maxn];
map <int, int> has[Maxn];
int R[Maxn][Maxn];
int A[Maxn], B[Maxn];
bool tb[Maxn], te[Maxn];
vector <int> neigh[Maxn];
int my[Maxn];
int fl[Maxn], par[Maxn];
int res;

int Get(int num, int pr) { return has[num].find(pr) == has[num].end()? 0: has[num][pr]; }

int getFlow()
{
	fill(fl, fl + n + 2, 0); fl[0] = Inf;
	priority_queue <ii> Q; Q.push(ii(Inf, 0));
	while (!Q.empty()) {
		int v = Q.top().second, f = Q.top().first; Q.pop();
		if (fl[v] != f) continue;
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (min(fl[v], R[v][u]) > fl[u]) {
				fl[u] = min(fl[v], R[v][u]); par[u] = v;
				Q.push(ii(fl[u], u));
			}
		}
	}
	if (fl[n + 1] == 0) return 0;
	int v = n + 1, res = fl[n + 1];
	while (v) {
		int u = par[v];
		R[u][v] -= res; R[v][u] += res;
		v = u;
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		for (int j = 2; j * j <= a[i]; j++)
			if (a[i] % j == 0) {
				int cnt = 0;
				while (a[i] % j == 0) { cnt++; a[i] /= j; }
				has[i][j] = cnt;
				P.insert(j);
			}
		if (a[i] > 1) { has[i][a[i]] = 1; P.insert(a[i]); }
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &A[i], &B[i]);
		if (A[i] % 2) swap(A[i], B[i]);
		neigh[A[i]].push_back(B[i]);
		neigh[B[i]].push_back(A[i]);
		if (!tb[A[i]]) { tb[A[i]] = true; neigh[0].push_back(A[i]); neigh[A[i]].push_back(0); }
		if (!te[B[i]]) { te[B[i]] = true; neigh[n + 1].push_back(B[i]); neigh[B[i]].push_back(n + 1); }
	}
	for (set <int>::iterator it = P.begin(); it != P.end(); it++) {
		for (int i = 1; i <= n; i++)
			my[i] = Get(i, *it);
		for (int i = 0; i < m; i++) {
			R[0][A[i]] = my[A[i]];
			R[A[i]][B[i]] = min(my[A[i]], my[B[i]]); R[B[i]][A[i]] = 0;
			R[B[i]][n + 1] = my[B[i]];
		}
		int fl;
		while ((fl = getFlow()) != 0)
			res += fl;
	}
	printf("%d\n", res);
	return 0;
}