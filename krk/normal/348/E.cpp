#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;
const int Maxm = 20;
const int Inf = 1000000000;

int n, m;
bool spec[Maxn];
vector <ii> neigh[Maxn];
int L[Maxn], P[Maxn][Maxm];
ll add[Maxn];
ii best[Maxn][3], dp[Maxn];
int res, rescnt;

void Traverse(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i].first;
		if (P[v][0] == u) continue;
		P[u][0] = v; L[u] = L[v] + 1;
		Traverse(u);
	}
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

void Add(int a, int b)
{
	add[a]++;
	add[b]++;
	int lca = getLCA(a, b);
	add[lca]--;
	add[P[lca][0]]--;
}

void addBest(ii best[], const ii &val)
{
	if (val > best[0]) { best[2] = best[1]; best[1] = best[0]; best[0] = val; }
	else if (val > best[1]) { best[2] = best[1]; best[1] = val; }
	else if (val > best[2]) best[2] = val;
}

ii Join(int v, const ii &a, const ii &b)
{
	if (a.first == b.first) return ii(a.first, v);
	return max(a, b);
}

ii joinAll(int v, const ii &av)
{
	if (best[v][0] == av) return Join(v, best[v][1], best[v][2]);
	if (best[v][1] == av) return Join(v, best[v][0], best[v][2]);
	return Join(v, best[v][0], best[v][1]);
}

ii Solve1(int v)
{
	fill(best[v], best[v] + 3, ii(-Inf, 0));
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i].first;
		if (u == P[v][0]) continue;
		ii got = Solve1(u);
		got.first += neigh[v][i].second;
		addBest(best[v], got);
	}
	if (spec[v]) addBest(best[v], ii(0, v));
	dp[v] = Join(v, best[v][0], best[v][1]);
	return dp[v];
}

void Solve2(int v, const ii &tp)
{
	ii my = Join(v, dp[v], tp);
	if (spec[v] && my.second != v) Add(v, my.second);
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i].first;
		if (u == P[v][0]) continue;
		ii ntp = joinAll(v, ii(dp[u].first + neigh[v][i].second, dp[u].second));
		ntp = Join(v, ntp, tp);
		ntp.first += neigh[v][i].second;
		Solve2(u, ntp);
	}
}

void Count(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i].first;
		if (u == P[v][0]) continue;
		Count(u);
		add[v] += add[u];
	}
	if (!spec[v]) {
		if (add[v] > res) { res = add[v]; rescnt = 0; }
		if (add[v] == res) rescnt++;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int v; scanf("%d", &v);
		spec[v] = true;
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		neigh[a].push_back(ii(b, c));
		neigh[b].push_back(ii(a, c));
	}
	Traverse(1);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	Solve1(1);
	Solve2(1, ii(-Inf, 0));
	Count(1);
	printf("%d %d\n", res, rescnt);
    return 0;
}