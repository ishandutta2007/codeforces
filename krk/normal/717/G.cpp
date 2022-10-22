#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 505;
const int Inf = 1000000000;

struct edge {
	int a, b, cap, cost;
	edge(int a = 0, int b = 0, int cap = 0, int cost = 0): a(a), b(b), cap(cap), cost(cost) {}
};

int n;
string S;
vector <edge> E;
vector <int> neigh[Maxn];
int m;
string W[Maxn];
int P[Maxn];
int x;
int N;
int dist[Maxn], par[Maxn];
int res;

void addEdge(int a, int b, int cap, int cost)
{
	neigh[a].push_back(E.size()); E.push_back(edge(a, b, cap, cost));
	neigh[b].push_back(E.size()); E.push_back(edge(b, a, 0, -cost));
}

bool Check(int pos, int ind)
{
	if (pos + W[ind].length() > n) return false;
	for (int i = 0; i < W[ind].length(); i++)
		if (S[pos + i] != W[ind][i]) return false;
	return true;
}

bool getFlow(int &res)
{
	fill(dist, dist + N, -Inf); dist[0] = 0;
	priority_queue <ii> Q; Q.push(ii(dist[0], 0));
	while (!Q.empty()) {
		int v = Q.top().second, d = Q.top().first; Q.pop();
		if (dist[v] != d) continue;
		for (int i = 0; i < neigh[v].size(); i++) {
			int e = neigh[v][i];
			if (E[e].cap > 0 && d + E[e].cost > dist[E[e].b]) {
				dist[E[e].b] = d + E[e].cost; par[E[e].b] = e;
				Q.push(ii(dist[E[e].b], E[e].b));
			}
		}
	}
	res = dist[N - 1];
	if (res <= -Inf) return false;
	int v = N - 1;
	while (v) {
		int e = par[v];
		E[e].cap--; E[e ^ 1].cap++;
		v = E[e].a;
	}
	return true;
}

int main()
{
	scanf("%d", &n); N = n + 2;
	cin >> S;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		cin >> W[i] >> P[i];
		for (int j = 0; j < n; j++)
			if (Check(j, i)) addEdge(1 + j, 1 + j + W[i].length(), 1, P[i]);
	}
	scanf("%d", &x);
	for (int i = 0; i <= n; i++)
		addEdge(i, i + 1, x, 0);
	int add;
	while (getFlow(add))
		res += add;
	printf("%d\n", res);
	return 0;
}