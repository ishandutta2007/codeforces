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
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

ii Join(const ii &a, const ii &b)
{
	if (a.first == 2 || b.first == 2) return ii(2, a.second);
	if (a.second == b.second) return ii(1, a.second);
	return ii(2, a.second);
}

int n;
vector <int> neigh[Maxn];
int c[Maxn];
ii my[Maxn];

void Traverse1(int v, int p = 0)
{
	my[v] = ii(1, c[v]);
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse1(u, v); my[v] = Join(my[v], my[u]);
	}
}

int Traverse2(int v, int p = 0) 
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		if (my[u].first == 2) return Traverse2(u, v);
	}
	return v;
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
		scanf("%d", &c[i]);
	Traverse1(1);
	int r = Traverse2(1);
	Traverse1(r);
	bool ok = true;
	for (int i = 0; i < neigh[r].size() && ok; i++) {
		int u = neigh[r][i];
		ok = my[u].first == 1;
	}
	if (ok) {
		printf("YES\n");
		printf("%d\n", r);
	} else printf("NO\n");
    return 0;
}