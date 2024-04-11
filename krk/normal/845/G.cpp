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

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxb = 30;

int n, m;
int X[Maxn], Y[Maxn], C[Maxn];
vector <ii> neigh[Maxn];
bool tk[Maxn];
int res[Maxn];
int best[Maxb];
bool zer;

void Solve(int v)
{
	tk[v] = true;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (tk[u.first]) continue;
		res[u.first] = res[v] ^ u.second;
		Solve(u.first);
	}
}

void Add(int x)
{
	for (int i = Maxb - 1; i >= 0; i--)
		if (x & 1 << i)
			if (best[i]) x ^= best[i];
			else { best[i] = x; return; }
}

int Get(int x)
{
	for (int i = Maxb - 1; i >= 0; i--)
		if (x & 1 << i) if (best[i]) x ^= best[i];
	return x;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y, c; scanf("%d %d %d", &x, &y, &c);
		neigh[x].push_back(ii(y, c));
		neigh[y].push_back(ii(x, c));
		X[i] = x; Y[i] = y; C[i] = c;
	}
	Solve(n);
	for (int i = 0; i < m; i++)
		Add(res[X[i]] ^ res[Y[i]] ^ C[i]);
	printf("%d\n", Get(res[1]));
	return 0;
}