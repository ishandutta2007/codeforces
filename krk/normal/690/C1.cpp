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
using namespace std;

const int Maxn = 1005;

int n, m;
vector <int> neigh[Maxn];
bool tk[Maxn];

void Traverse(int v)
{
	if (tk[v]) return;
	tk[v] = true;
	for (int i = 0; i < neigh[v].size(); i++)
		Traverse(neigh[v][i]);
}

int main()
{
	scanf("%d %d", &n, &m);
	if (n - 1 != m) { printf("no\n"); return 0; }
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1);
	for (int i = 1; i <= n; i++)
		if (!tk[i]) { printf("no\n"); return 0; }
	printf("yes\n");
	return 0;
}