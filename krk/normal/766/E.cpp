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

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxb = 21;

int n;
int a[Maxn];
vector <int> neigh[Maxn];
ii has[Maxn][Maxb];
ll res;

void Traverse(int v, int p = 0)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v);
		for (int j = 0; j < Maxb; j++) {
			if (a[v] & 1 << j)
				res += (ll(has[v][j].first) * has[u][j].first + ll(has[v][j].second) * has[u][j].second + has[u][j].first) * ll(1 << j);
			else res += (ll(has[v][j].first) * has[u][j].second + ll(has[v][j].second) * has[u][j].first + has[u][j].second) * ll(1 << j);
			has[v][j].first += has[u][j].first; has[v][j].second += has[u][j].second;
		}
	}
	res += a[v];
	for (int i = 0; i < Maxb; i++)
		if (a[v] & 1 << i) { swap(has[v][i].first, has[v][i].second); has[v][i].second++; }
		else has[v][i].first++;
}

int main() 
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1);
	printf("%I64d\n", res);
    return 0;
}