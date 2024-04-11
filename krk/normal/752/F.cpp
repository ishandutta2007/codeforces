#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 200005;

int n, k;
vector <int> neigh[Maxn];
int c[Maxn], cnt[Maxn];
int par[Maxn];
int cur;
int loc;
vector <int> has[Maxn];
vector <ii> res;

void Traverse1(int v, int p = 0)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse1(u, v); cnt[v] += cnt[u];
	}
}

int Get(int v, int p = 0)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		if (cnt[u] > k / 2) return Get(u, v);
	}
	return v;
}

void Traverse2(int v, int p, int col)
{
	par[v] = col;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse2(u, v, col);
	}
}

int main()
{
	scanf("%d %d", &n, &k); k *= 2;
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]); cnt[c[i]]++;
	}
	Traverse1(1);
	loc = Get(1);
	printf("1\n%d\n", loc);
	cur++;
	for (int i = 0; i < neigh[loc].size(); i++) {
		int u = neigh[loc][i];
		Traverse2(u, loc, cur++);
	}
	for (int i = 1; i <= k; i++)
		has[par[c[i]]].push_back(c[i]);
	priority_queue <ii> Q;
	for (int i = 0; i < cur; i++) if (has[i].size() > 0)
		Q.push(ii(has[i].size(), i));
	while (Q.size() > 1) {
		ii a = Q.top(); Q.pop();
		ii b = Q.top(); Q.pop();
		res.push_back(ii(has[a.second].back(), has[b.second].back()));
		has[a.second].pop_back(); has[b.second].pop_back();
		if (!has[a.second].empty()) Q.push(ii(has[a.second].size(), a.second));
		if (!has[b.second].empty()) Q.push(ii(has[b.second].size(), b.second));
	}
	while (!Q.empty()) {
		ii a = Q.top();
		res.push_back(ii(has[a.second][has[a.second].size() - 2], has[a.second].back()));
		has[a.second].pop_back(); has[a.second].pop_back();
		if (!has[a.second].empty()) Q.push(ii(has[a.second].size(), a.second));
	}
	for (int i = 0; i < res.size(); i++)
		printf("%d %d %d\n", res[i].first, res[i].second, loc);
	return 0;
}