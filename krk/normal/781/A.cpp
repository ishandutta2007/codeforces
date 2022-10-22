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

const int Maxn = 200005;

int n;
vector <int> neigh[Maxn];
int k;
int res[Maxn];

void Traverse(int v, int p, int par, int my)
{
	int c = 0;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		c++;
		while (c == par || c == my) c++;
		res[u] = c;
		Traverse(u, v, my, c);
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
	for (int i = 1; i <= n; i++)
		k = max(k, int(neigh[i].size()) + 1);
	res[1] = 1;
	Traverse(1, 0, 0, 1);
	printf("%d\n", k);
	for (int i = 1; i <= n; i++)
		printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    return 0;
}