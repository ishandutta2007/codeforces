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

const int Maxn = 500005;

int n;
vector <int> neigh[Maxn];
multiset <int> S;
int res;

void Traverse(int v, int p, int h = 0)
{
	if (neigh[v].size() == 1) S.insert(h);
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v, h + 1);
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
	for (int i = 0; i < neigh[1].size(); i++) {
		int u = neigh[1][i];
		S.clear();
		Traverse(u, 1);
		int cand = -1;
		for (multiset <int>::iterator it = S.begin(); it != S.end(); it++)
			cand = max(cand + 1, *it);
		res = max(res, cand + 1);
	}
	printf("%d\n", res);
    return 0;
}