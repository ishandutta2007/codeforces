#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 100005;
const int Maxk = 20;

int n;
vector <ii> neigh[Maxn];
ll best[Maxn][2];
ll my[Maxn];
int P[Maxn][Maxk];
int q;
ll X;
int st[Maxn];
int res;

void insertBest(int v, ll x)
{
	if (x > best[v][0]) best[v][1] = best[v][0], best[v][0] = x;
	else if (x > best[v][1]) best[v][1] = x;
}

ll Get(int v, ll x)
{
	if (x != best[v][0]) return best[v][0];
	return best[v][1];
}

void Traverse1(int v, int p = 0)
{
	if (neigh[v].size() > 1) best[v][0] = best[v][1] = -Inf;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (p != u.first) {
			Traverse1(u.first, v);
			insertBest(v, best[u.first][0] + u.second);
		}
	}
}

void Traverse2(int v, ll ft, int p = 0)
{
	my[v] = max(ft, best[v][0]);
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (p != u.first)
			Traverse2(u.first, max(ft, Get(v, best[u.first][0] + u.second)) + u.second, v);
	}
}

void Traverse3(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i].first;
		if (P[v][0] != u) { P[u][0] = v; Traverse3(u); }
	}
}

int Traverse4(int v)
{
	int cur = st[v];
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (P[v][0] != u.first) cur += Traverse4(u.first);
	}
	res = max(res, cur);
	return cur;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		neigh[a].push_back(ii(b, c)); neigh[b].push_back(ii(a, c));
	}
	Traverse1(1);

	ll ft = -Inf;
	if (neigh[1].size() == 1) ft = 0;
	Traverse2(1, ft);

	int mn = 1;
	for (int i = 1; i <= n; i++)
		if (my[i] < my[mn]) mn = i;
	Traverse3(mn);
	for (int j = 1; j < Maxk; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];

	scanf("%d", &q);
	while (q--) {
		scanf("%I64d", &X);
		res = 0;
		fill(st + 1, st + n + 1, 0);
		for (int i = 1; i <= n; i++) {
			st[i]++;
			int v = i;
			for (int j = Maxk - 1; j >= 0; j--)
				if (my[P[v][j]] + X >= my[i]) v = P[v][j];
			st[P[v][0]]--;
		}
		Traverse4(mn);
		printf("%d\n", res);
	}
	return 0;
}