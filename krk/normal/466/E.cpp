#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;
const int Maxk = 20;

int n, m;
int typ[Maxn], a[Maxn], b[Maxn];
vector <int> neigh[Maxn];
bool haspar[Maxn];
int L[Maxn], P[Maxn][Maxk];
int par[Maxn];
int cur, yth[Maxn], eld[Maxn];

void Traverse(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		L[u] = L[v] + 1; P[u][0] = v;
		Traverse(u);
	}
}

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool canReach(int v, int u)
{
	for (int i = Maxk - 1; i >= 0; i--)
		if (L[v] - (1 << i) >= L[u])
			v = P[v][i];
	return v == u;
}

bool Solve(int person, int packet)
{
	if (getPar(person) != getPar(eld[packet])) return false;
	if (L[person] > L[yth[packet]] || L[eld[packet]] > L[person]) return false;
	return canReach(yth[packet], person);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &typ[i], &a[i]);
		if (typ[i] == 1 || typ[i] == 3)
			scanf("%d", &b[i]);
		if (typ[i] == 1) {
			neigh[b[i]].push_back(a[i]);
			haspar[a[i]] = true;
		}
	}
	for (int i = 1; i <= n; i++) if (!haspar[i])
		Traverse(i);
	for (int j = 1; j < Maxk; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	for (int i = 1; i <= n; i++)
		par[i] = i;
	for (int i = 0; i < m; i++)
		if (typ[i] == 1) par[getPar(a[i])] = getPar(b[i]);
		else if (typ[i] == 2) {
				cur++;
				yth[cur] = a[i]; eld[cur] = getPar(a[i]);
			} else if (typ[i] == 3)
				printf("%s\n", Solve(a[i], b[i])? "YES": "NO");
	return 0;
}