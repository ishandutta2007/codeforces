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

const int Maxn = 200005;

int n;
int a[Maxn];
vector <int> neigh[Maxn];
int res[Maxn];

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

void Process(int v, int p, set <int> &S, int my)
{
	set <int> nS;
	for (set <int>::iterator it = S.begin(); it != S.end(); it++)
		nS.insert(gcd(*it, a[v]));
	nS.insert(my); my = gcd(my, a[v]);
	res[v] = max(my, *nS.rbegin());
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Process(u, v, nS, my);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; i++) {
		int x, y; scanf("%d %d", &x, &y);
		neigh[x].push_back(y);
		neigh[y].push_back(x);
	}
	set <int> S;
	Process(1, 0, S, 0);
	for (int i = 1; i <= n; i++)
		printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
	return 0;
}