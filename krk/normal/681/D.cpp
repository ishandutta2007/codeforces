#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

int n, m;
vector <int> neigh[Maxn];
int a[Maxn];
int in[Maxn];
vector <int> gneigh[Maxn];
int tk[Maxn];
vector <int> seq;

void Traverse1(int v, int best)
{
	if (best != a[v]) { 
		gneigh[a[v]].push_back(best); best = a[v];
	} 
	if (a[v] != v) gneigh[a[v]].push_back(v);
	for (int i = 0; i < neigh[v].size(); i++)
		Traverse1(neigh[v][i], best);
}

bool Traverse2(int v)
{
	if (tk[v] == 1) return false;
	if (tk[v] == 2) return true;
	tk[v] = 1;
	for (int i = 0; i < gneigh[v].size(); i++)
		if (!Traverse2(gneigh[v][i])) return false;
	seq.push_back(v);
	tk[v] = 2;
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int p, q; scanf("%d %d", &p, &q);
		neigh[p].push_back(q); in[q]++;
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) if (in[i] == 0)
		Traverse1(i, i);
	for (int i = 1; i <= n; i++) if (tk[i] == 0)
		if (!Traverse2(i)) { printf("-1\n"); return 0; }
	printf("%d\n", n);
	for (int i = int(seq.size()) - 1; i >= 0; i--)
		printf("%d\n", seq[i]);
	return 0;
}