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
#include <iomanip>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxl = 20;

int n;
vector <int> neigh[Maxn];
char let[Maxn];
bool er[Maxn];
int has[1 << Maxl];
ll res[Maxn];
int cnt[Maxn];

void Traverse(int v, int p = 0)
{
	cnt[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p || er[u]) continue;
		Traverse(u, v); cnt[v] += cnt[u];
	}
}

int getCentroid(int v, int p, int siz)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p || er[u]) continue;
		if (cnt[u] > siz / 2) return getCentroid(u, v, siz);
	}
	return v;
}

ll Calc(int v, int p, int cur)
{
	cur ^= 1 << int(let[v] - 'a');
	ll my = has[cur];
	for (int i = 0; i < Maxl; i++)
		my += has[cur ^ 1 << i];
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p || er[u]) continue;
		my += Calc(u, v, cur);
	}
	res[v] += my;
	return my;
}

void Update(int v, int p, int cur, int add)
{
	cur ^= 1 << int(let[v] - 'a');
	has[cur] += add;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p || er[u]) continue;
		Update(u, v, cur, add);
	}
}

void Solve(int v)
{
	Traverse(v);
	int c = getCentroid(v, 0, cnt[v]);
	int my = 1 << int(let[c] - 'a');
	has[my]++; res[c]++;
	for (int i = 0; i < neigh[c].size(); i++) {
		int u = neigh[c][i];
		if (er[u]) continue;
		ll g = Calc(u, c, 0);
		res[c] += g;
		Update(u, c, my, 1);
	}
	for (int i = 0; i < neigh[c].size(); i++) {
		int u = neigh[c][i];
		if (er[u]) continue;
		Update(u, c, my, -1);
	}
	has[my]--;
	for (int i = int(neigh[c].size()) - 1; i >= 0; i--) {
		int u = neigh[c][i];
		if (er[u]) continue;
		Calc(u, c, 0);
		Update(u, c, my, 1);
	}
	for (int i = int(neigh[c].size()) - 1; i >= 0; i--) {
		int u = neigh[c][i];
		if (er[u]) continue;
		Update(u, c, my, -1);
	}
	er[c] = true;
	for (int i = 0; i < neigh[c].size(); i++) {
		int u = neigh[c][i];
		if (er[u]) continue;
		Solve(u);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	scanf("%s", let + 1);
	Solve(1);
	for (int i = 1; i <= n; i++)
		printf("%I64d%c", res[i], i + 1 <= n? ' ': '\n');
	return 0;
}