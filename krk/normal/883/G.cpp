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

const int Maxn = 300005;

int n, m, s;
int t[Maxn], u[Maxn], v[Maxn];
bool inv[Maxn];
vector <ii> neigh[Maxn];
bool tk[Maxn];

void Print(int res)
{
	printf("%d\n", res);
	for (int i = 0; i < m; i++)
		if (t[i] == 2) printf("%c", inv[i]? '-': '+');
	printf("\n");
}

int Fill1(int s)
{
	if (tk[s]) return 0;
	int res = 1; tk[s] = true;
	for (int i = 0; i < neigh[s].size(); i++) {
		ii z = neigh[s][i];
		if (tk[z.first]) continue;
		int ind = z.second;
		if (t[ind] == 2)
			inv[ind] = v[ind] == s;
		res += Fill1(z.first);
	}
	return res;
}

int Fill2(int s)
{
	if (tk[s]) return 0;
	int res = 1; tk[s] = true;
	for (int i = 0; i < neigh[s].size(); i++) {
		ii z = neigh[s][i];
		if (tk[z.first]) continue;
		int ind = z.second;
		if (t[ind] == 2)
			inv[ind] = u[ind] == s;
		else res += Fill2(z.first);
	}
	return res;
}

int main()
{
	scanf("%d %d %d", &n, &m, &s);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &t[i], &u[i], &v[i]);
		neigh[u[i]].push_back(ii(v[i], i));
		if (t[i] == 2) neigh[v[i]].push_back(ii(u[i], i));
	}
	int res = Fill1(s);
	Print(res);
	fill(tk, tk + Maxn, false);
	res = Fill2(s);
	Print(res);
	return 0;
}