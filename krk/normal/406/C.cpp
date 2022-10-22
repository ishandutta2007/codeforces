#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 100005;

int n, m;
ii E[Maxm];
vector <ii> neigh[Maxn];
bool tk[Maxm];

int Solve(int v)
{
	vector <int> av;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (tk[u.second]) continue;
		av.push_back(u.first); tk[u.second] = true;
	}
	int sav = 0;
	for (int i = 0; i < av.size(); i++) {
		int got = Solve(av[i]);
		if (got) { printf("%d %d %d\n", got, av[i], v); got = 0; }
		else got = av[i];
		if (sav && got) { printf("%d %d %d\n", sav, v, got); sav = 0; }
		else sav = max(sav, got);
	}
	return sav;
}

int main()
{
	scanf("%d %d", &n, &m);
	if (m % 2) { printf("No solution\n"); return 0; }
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &E[i].first, &E[i].second);
		neigh[E[i].first].push_back(ii(E[i].second, i));
		neigh[E[i].second].push_back(ii(E[i].first, i));
	}
	Solve(1);
	return 0;
}