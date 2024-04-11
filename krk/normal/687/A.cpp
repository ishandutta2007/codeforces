#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

int n, m;
int tk[Maxn];
vector <int> neigh[Maxn];
vector <int> a, b;

bool Traverse(int v, int col)
{
	if (tk[v] == col) return true;
	if (tk[v] == -col) return false;
	tk[v] = col;
	if (col == 1) a.push_back(v);
	else b.push_back(v);
	for (int i = 0; i < neigh[v].size(); i++)
		if (!Traverse(neigh[v][i], -col)) return false;
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) if (!tk[i])
		if (!Traverse(i, 1)) { printf("-1\n"); return 0; }
	printf("%d\n", a.size());
	for (int i = 0; i < a.size(); i++)
		printf("%d%c", a[i], i + 1 < a.size()? ' ': '\n');
	printf("%d\n", b.size());
	for (int i = 0; i < b.size(); i++)
		printf("%d%c", b[i], i + 1 < b.size()? ' ': '\n');
	return 0;
}