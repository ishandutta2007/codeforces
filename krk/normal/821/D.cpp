#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};
const int Maxn = 100005;
const int Inf = 1000000000;

int n, m, k;
int X[Maxn], Y[Maxn];
map <ii, int> ID;
vector <ii> neigh[Maxn];
int dist[Maxn];

void addIn(int a, int b)
{
	neigh[a].push_back(ii(b, 1));
	neigh[b].push_back(ii(a, 0));
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &X[i], &Y[i]); X[i]--; Y[i]--;
		ID[ii(X[i], Y[i])] = n + m + i;
	}
	for (map <ii, int>::iterator it = ID.begin(); it != ID.end(); it++) {
		ii v = it->first;
		int id = it->second;
		for (int d = 0; d < Maxd; d++) {
			ii u = ii(v.first + dy[d], v.second + dx[d]);
			if (ID.find(u) != ID.end()) neigh[id].push_back(ii(ID[u], 0));
		}
		if (v.first > 0) addIn(id, v.first - 1);
		addIn(id, v.first);
		if (v.first + 1 < n) addIn(id, v.first + 1);
		if (v.second > 0) addIn(id, n + v.second - 1);
		addIn(id, n + v.second);
		if (v.second + 1 < m) addIn(id, n + v.second + 1);
	}
	fill(dist, dist + Maxn, Inf); dist[ID[ii(0, 0)]] = 0;
	priority_queue <ii> Q; Q.push(ii(0, ID[ii(0, 0)]));
	while (!Q.empty()) {
		int v = Q.top().second, d = -Q.top().first; Q.pop();
		if (dist[v] != d) continue;
		if (v == n - 1 || v == n + m - 1 || v >= n + m && X[v - n - m] == n - 1 && Y[v - n - m] == m - 1) {
			printf("%d\n", d); return 0;
		}
		for (int i = 0; i < neigh[v].size(); i++) {
			ii u = neigh[v][i];
			if (d + u.second < dist[u.first]) {
				dist[u.first] = d + u.second;
				Q.push(ii(-dist[u.first], u.first));
			}
		}
	}
	printf("-1\n");
	return 0;
}