#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 8;
const int Maxb = 3;

int n, m;
int adj[Maxm][Maxm];
vector <ii> E;
int deg[Maxn];
bool taken[Maxn];
vector <int> neigh[Maxn];
vector <int> Q;
vector <int> B[Maxb];
vector <ii> res;
bool solved;

void Print()
{
	for (int i = 0; i < res.size(); i++)
		printf("%d %d\n", res[i].first, res[i].second);
}

void Gen(int v)
{
	if (v >= E.size()) {
		if (res.size() == m) { Print(); solved = true; }
	} else {
		Gen(v + 1);
		if (solved) return;
		if (deg[E[v].first] && deg[E[v].second]) {
			deg[E[v].first]--; deg[E[v].second]--; res.push_back(E[v]);
			Gen(v + 1);
			deg[E[v].first]++; deg[E[v].second]++; res.pop_back();
		}
	}
}

void solveSmall()
{
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		adj[a][b] = adj[b][a] = true;
	}
	for (int i = 1; i <= n; i++) {
		deg[i] = 2;
		for (int j = i + 1; j <= n; j++)
			if (!adj[i][j]) E.push_back(ii(i, j));
	}
	Gen(0);
	if (!solved) printf("-1\n");
}

void Fill(int v, int p)
{
	taken[v] = true; Q.push_back(v);
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		if (!taken[u]) Fill(u, v);
	}
}

bool hasEdge(int a, int b)
{
	for (int i = 0; i < neigh[a].size(); i++)
		if (neigh[a][i] == b) return true;
	return false;
}

void solveBig()
{
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
		deg[a]++; deg[b]++;
	}
	for (int i = 1; i <= n; i++) if (!taken[i] && deg[i] <= 1) {
		Q.clear(); Fill(i, -1);
		for (int j = 0; j < Q.size(); j++)
			B[j % 2].push_back(Q[j]);
	}
	for (int i = 1; i <= n; i++) if (!taken[i]) {
		Q.clear(); Fill(i, -1);
		for (int j = 0; j + 1 < Q.size(); j++)
			B[j % 2].push_back(Q[j]);
		if (Q.size() % 2) B[2].push_back(Q.back());
		else B[1].push_back(Q.back());
	}
	int a = 0, b = 1;
	if (!B[2].empty() && B[2].size() <= 2) {
		while (hasEdge(B[0][a], B[2][0])) a++;
		b = 0;
		while (b == a || hasEdge(B[0][b], B[2].back())) b++;
		if (res.size() < m) res.push_back(ii(B[0][a], B[2][0]));
		if (B[2].size() == 2 && res.size() < m) res.push_back(ii(B[2][0], B[2][1]));
		if (res.size() < m) res.push_back(ii(B[2].back(), B[0][b]));
	} else if (res.size() < m) res.push_back(ii(B[0][a], B[0][b]));
	int was = a;
	for (int i = 0; i < B[0].size() && res.size() < m; i++) if (i != a && i != b) {
		res.push_back(ii(B[0][was], B[0][i])); was = i;
	}
	if (res.size() < m) res.push_back(ii(B[0][was], B[0][b]));
	was = 0;
	for (int i = 1; i < B[1].size() && res.size() < m; i++) {
		res.push_back(ii(B[1][was], B[1][i])); was = i;
	}
	if (res.size() < m) res.push_back(ii(B[1][was], B[1][0]));
	if (B[2].size() > 2) {
		was = 0;
		for (int i = 1; i < B[2].size() && res.size() < m; i++) {
			res.push_back(ii(B[2][was], B[2][i])); was = i;
		}
		if (res.size() < m) res.push_back(ii(B[2][was], B[2][0]));
	}
	Print();
}

int main()
{
	scanf("%d %d", &n, &m);
	if (n <= 7) solveSmall();
	else solveBig();
	return 0;
}