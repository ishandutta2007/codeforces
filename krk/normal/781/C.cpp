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

int n, m, k;
vector <int> neigh[Maxn];
bool tk[Maxn];
vector <int> res;
int pnt;

void Traverse(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (tk[u]) continue;
		tk[u] = true; 
		res.push_back(u);
		Traverse(u);
		res.push_back(v);
	}
}

int main() 
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	tk[1] = true; Traverse(1);
	for (int i = 0; i < k; i++)
		if (pnt >= res.size()) printf("1 1\n");
		else {
			int nd = 2 * n / k + int(2 * n % k > 0);
			int lim = min(int(res.size()), pnt + nd);
			printf("%d", lim - pnt);
			while (pnt < lim)
				printf(" %d", res[pnt++]);
			printf("\n");
		}
    return 0;
}