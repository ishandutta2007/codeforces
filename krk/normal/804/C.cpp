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

const int Maxn = 300005;

int n, m;
vector <int> my[Maxn];
vector <int> neigh[Maxn];
int col[Maxn];

void Traverse(int v, int p = 0)
{
	set <int> S;
	for (int i = 0; i < my[v].size(); i++) {
		int ind = my[v][i];
		if (col[ind]) S.insert(col[ind]);
	}
	int give = 1;
	for (int i = 0; i < my[v].size(); i++) {
		int ind = my[v][i];
		if (!col[ind]) {
			while (S.find(give) != S.end()) give++;
			col[ind] = give; S.insert(give);
		}
	}
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int c; scanf("%d", &c);
		my[i].resize(c);
		for (int j = 0; j < c; j++)
			scanf("%d", &my[i][j]);
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1);
	int mx = 0;
	for (int i = 1; i <= m; i++) {
		if (!col[i]) col[i] = 1;
		mx = max(mx, col[i]);
	}
	printf("%d\n", mx);
	for (int i = 1; i <= m; i++)
		printf("%d%c", col[i], i + 1 <= m? ' ': '\n');
	return 0;
}