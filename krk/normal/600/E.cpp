#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int c[Maxn];
vector <int> neigh[Maxn];
map <int, int> times[Maxn];
map <int, ll> cnt[Maxn];
int par[Maxn];
ll res[Maxn];

void Merge(int a, int b)
{
	for (map <int, int>::iterator it = times[par[b]].begin(); it != times[par[b]].end(); it++) {
		int old = times[par[a]][it->first];
		if (old > 0) {
			map <int, ll>::iterator fit = cnt[par[a]].find(old);
			if (fit->second == it->first) cnt[par[a]].erase(fit);
			else fit->second -= it->first;
		}
		times[par[a]][it->first] += it->second;
		cnt[par[a]][times[par[a]][it->first]] += it->first;
	}
	times[par[b]].clear(); cnt[par[b]].clear();
	par[b] = par[a];
}

void Traverse(int v, int p = 0)
{
	par[v] = v;
	times[v][c[v]] = 1; cnt[v][1] += c[v];
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v);
		if (times[par[v]].size() >= times[par[u]].size()) Merge(v, u);
		else Merge(u, v);
	}
	res[v] = cnt[par[v]].rbegin()->second;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1);
	for (int i = 1; i <= n; i++)
		printf("%I64d%c", res[i], i + 1 <= n? ' ': '\n');
	return 0;
}