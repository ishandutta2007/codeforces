#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;
typedef pair <int, int> ii;

const ll Inf = 1000000000000000000ll;
const int Maxn = 200005;
const int Maxm = 21;

int n, m, s;
vector <ii> neigh[Maxn];
ll dist[Maxn];
vector <int> par[Maxn];
int P[Maxn][Maxm], L[Maxn];
priority_queue <lli> Q;
int has[Maxn];

int getLCA(int a, int b)
{
	if (L[a] < L[b]) swap(a, b);
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b]) a = P[a][i];
	if (a == b) return a;
	for (int i = Maxm - 1; i >= 0; i--)
		if (P[a][i] != P[b][i]) a = P[a][i], b = P[b][i];
	return P[a][0];
}

int Traverse()
{
	if (Q.empty()) return 0;
	ll d = -Q.top().first; int v = Q.top().second; Q.pop();
	if (dist[v] != d) return Traverse();
	if (v != s) {
		int cur = par[v][0];
		for (int i = 1; i < par[v].size(); i++)
			cur = getLCA(cur, par[v][i]);
		P[v][0] = cur; L[v] = L[cur] + 1;
		for (int i = 1; i < Maxm; i++)
			P[v][i] = P[P[v][i - 1]][i - 1];
	}
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (d + u.second < dist[u.first]) { 
			dist[u.first] = d + u.second; Q.push(lli(-dist[u.first], u.first)); 
			par[u.first].clear();
		}
		if (d + u.second == dist[u.first]) par[u.first].push_back(v);
	}
	int res = Traverse();
	if (v != s) {
		res = max(res, 1 + has[v]);
		has[P[v][0]] += 1 + has[v];
	}
	return res;
}

int main() 
{
	scanf("%d %d %d", &n, &m, &s);
	while (m--) {
		int a, b, w; scanf("%d %d %d", &a, &b, &w);
		neigh[a].push_back(ii(b, w));
		neigh[b].push_back(ii(a, w));
	}
	for (int j = 0; j < Maxm; j++)
		P[s][j] = s;
	L[s] = 0; 
	fill(dist, dist + n + 1, Inf); dist[s] = 0;
	Q.push(lli(0, s));
	printf("%d\n", Traverse());
    return 0;
}