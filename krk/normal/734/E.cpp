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
int col[Maxn];
vector <int> neigh[Maxn];
int mx[Maxn][2];
int res = Maxn;

void Update(int v, int val)
{
	if (val > mx[v][0]) mx[v][1] = mx[v][0], mx[v][0] = val;
	else if (val > mx[v][1]) mx[v][1] = val;
}

int Get(int v, int val)
{
	return mx[v][0] == val? mx[v][1]: mx[v][0];
}

void Traverse(int v, int p = 0)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v);
		Update(v, mx[u][0] + (col[v] != col[u]));
	}
}

void Traverse2(int v, int p, int ft)
{
	res = min(res, max(ft, mx[v][0]));
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		int nft = max(ft, Get(v, mx[u][0] + (col[v] != col[u])));
		Traverse2(u, v, nft + (col[v] != col[u]));
	}
}

int main() 
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &col[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1);
	Traverse2(1, 0, 0);
	printf("%d\n", res);
    return 0;
}