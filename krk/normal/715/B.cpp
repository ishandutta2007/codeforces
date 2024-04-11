#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 10005;
const ll Inf = 1000000000000000000ll;

int n, m, L, s, t;
int a[Maxn], b[Maxn];
ll w[Maxn];
bool mod[Maxn];
vector <ii> neigh[Maxn];
ll dist[Maxn], dist2[Maxn];

void Solve1()
{
	fill(dist, dist + n + 1, Inf); dist[t] = 0;
	priority_queue <lli> Q; Q.push(lli(-dist[t], t));
	while (!Q.empty()) {
		int v = Q.top().second; ll d = -Q.top().first; Q.pop();
		if (d != dist[v]) continue;
		for (int i = 0; i < neigh[v].size(); i++) {
			ii u = neigh[v][i];
			if (d + w[u.second] < dist[u.first]) {
				dist[u.first] = d + w[u.second];
				Q.push(ii(-dist[u.first], u.first));
			}
		}
	}
}

void Solve2()
{
	fill(dist2, dist2 + n + 1, Inf); dist2[s] = 0;
	priority_queue <lli> Q; Q.push(lli(-dist2[s], s));
	while (!Q.empty()) {
		int v = Q.top().second; ll d = -Q.top().first; Q.pop();
		if (d != dist2[v]) continue;
		for (int i = 0; i < neigh[v].size(); i++) {
			ii u = neigh[v][i];
			if (d + w[u.second] + dist[u.first] < L)
				if (mod[u.second]) w[u.second] += L - (d + w[u.second] + dist[u.first]);
				else if (d + w[u.second] < dist2[u.first]) {
					dist2[u.first] = d + w[u.second];
					Q.push(ii(-dist2[u.first], u.first));
				}
		}
	}
}

int main()
{
	scanf("%d %d %d %d %d", &n, &m, &L, &s, &t);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %I64d", &a[i], &b[i], &w[i]);
		if (w[i] == 0) { w[i] = 1; mod[i] = true; }
		neigh[a[i]].push_back(ii(b[i], i));
		neigh[b[i]].push_back(ii(a[i], i));
	}
	Solve1();
	if (dist[s] > L) { printf("NO\n"); return 0; }
	Solve2();
	if (dist2[t] >= Inf) {
		printf("YES\n");
		for (int i = 0; i < m; i++)
			printf("%d %d %I64d\n", a[i], b[i], w[i]);
	} else printf("NO\n");
	return 0;
}