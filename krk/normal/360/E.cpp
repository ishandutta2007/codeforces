#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;
typedef pair <int, int> ii;

const int Maxn = 20005;
const ll Inf = 1000000000000000000ll;

int n, m, k;
int s1, s2, f;
int a[Maxn], b[Maxn], lef[Maxn], rig[Maxn];
vector <ii> neigh[Maxn];
ll dist1[Maxn], dist2[Maxn];

void Solve(bool wineq)
{
	fill(dist1, dist1 + n + 1, Inf);
	fill(dist2, dist2 + n + 1, Inf);
	priority_queue <lli> Q;
	dist1[s1] = 0; Q.push(lli(0, s1));
	dist2[s2] = 0; Q.push(lli(0, s2));
	while (!Q.empty()) {
		int v = Q.top().second;
		ll d = -Q.top().first; Q.pop();
		if (min(dist1[v], dist2[v]) != d) continue;
		if (dist1[v] < dist2[v] || wineq && dist1[v] == dist2[v])
			for (int i = 0; i < neigh[v].size(); i++) {
				int u = neigh[v][i].first;
				ll cand = d + lef[neigh[v][i].second];
				if (cand < min(dist1[u], dist2[u])) {
					dist1[u] = cand;
					Q.push(lli(-dist1[u], u));
				} else dist1[u] = min(dist1[u], cand);
			}
		else for (int i = 0; i < neigh[v].size(); i++) {
				int u = neigh[v][i].first;
				ll cand = d + rig[neigh[v][i].second];
				if (cand < min(dist1[u], dist2[u])) {
					dist2[u] = cand;
					Q.push(lli(-dist2[u], u));
				} else dist2[u] = min(dist2[u], cand);
			}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	scanf("%d %d %d", &s1, &s2, &f);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a[i], &b[i], &lef[i]);
		rig[i] = lef[i];
		neigh[a[i]].push_back(ii(b[i], i));
	}
	for (int i = m; i < m + k; i++) {
		scanf("%d %d %d %d", &a[i], &b[i], &lef[i], &rig[i]);
		neigh[a[i]].push_back(ii(b[i], i));
	}
	if (s1 == s2) {
		printf("DRAW\n");
		for (int i = m; i < m + k; i++)
			printf("%d%c", lef[i], i + 1 < m + k? ' ': '\n');
		return 0;
	}
	Solve(false);
	if (dist1[f] < dist2[f]) {
		printf("WIN\n");
		for (int i = m; i < m + k; i++)
			printf("%d%c", dist1[a[i]] < dist2[a[i]] && dist1[b[i]] < dist2[b[i]]? lef[i]: rig[i], i + 1 < m + k? ' ': '\n');
		return 0;
	}
	Solve(true);
	if (dist1[f] <= dist2[f]) {
		printf("DRAW\n");
		for (int i = m; i < m + k; i++)
			printf("%d%c", dist1[a[i]] <= dist2[a[i]] && dist1[b[i]] <= dist2[b[i]]? lef[i]: rig[i], i + 1 < m + k? ' ': '\n');
		return 0;
	}
	printf("LOSE\n");
    return 0;
}