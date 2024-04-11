#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 5005;
const int Maxl = 26;
const int Inf = 1000000000;

int n, N;
string S;
int b[Maxn];
int R[Maxn][Maxn], C[Maxn][Maxn];
int freq[Maxl];
vector <int> neigh[Maxn];
int dist[Maxn], par[Maxn];
int sum;

void addEdge(int a, int b, int cap, int cost)
{
	R[a][b] = cap; R[b][a] = 0;
	C[a][b] = cost; C[b][a] = -cost;
	neigh[a].push_back(b);
	neigh[b].push_back(a);
}

int getMid(int pos, int let)
{
	return 1 + Maxl + pos * Maxl + let;
}

int getLast(int pos)
{
	return 1 + Maxl + (n / 2) * Maxl + pos;
}

bool getFlow(int &res)
{
	fill(dist, dist + N, Inf); dist[0] = 0;
	priority_queue <ii> Q; Q.push(ii(-dist[0], 0));
	while (!Q.empty()) {
		int d = -Q.top().first, v = Q.top().second; Q.pop();
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (R[v][u] > 0 && d + C[v][u] < dist[u]) {
				dist[u] = d + C[v][u]; par[u] = v;
				Q.push(ii(-dist[u], u));
			}
		}
	}
	int v = N - 1;
	res = dist[v];
	if (res >= Inf) return false;
	while (v) {
		int u = par[v];
		R[u][v]--; R[v][u]++;
		v = u;
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	N = 1 + Maxl + (n / 2) * Maxl + n / 2 + 1;
	cin >> S;
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]); sum += b[i];
	}
	for (int i = 0; i < n; i++)
		freq[S[i] - 'a']++;
	for (int i = 0; i < Maxl; i++) {
		addEdge(0, i + 1, freq[i], 0);
		for (int j = 0; j < n / 2; j++) {
			int cost = 0;
			if ('a' + i != S[j] && 'a' + i != S[n - 1 - j]) cost = b[j] + b[n - 1 - j];
			else if (S[j] == S[n - 1 - j]) {
				int u = b[j], v = b[n - 1 - j];
				if (u < v) swap(u, v);
				cost = -u + v;
			} else if ('a' + i == S[j]) cost = -b[j] + b[n - 1 - j];
				   else cost = -b[n - 1 - j] + b[j];
			addEdge(i + 1, getMid(j, i), 1, cost);
		}
	}
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < Maxl; j++)
			addEdge(getMid(i, j), getLast(i), 1, 0);
	for (int i = 0; i < n / 2; i++)
		addEdge(getLast(i), N - 1, 2, 0);
	int got = 0, cost;
	while (getFlow(cost)) got += cost;
	printf("%d\n", sum - got / 2);
	return 0;
}