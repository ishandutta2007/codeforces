#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;
const int Maxm = 30005;
const int Inf = 2000000007;

int n, m;
int s, t;
int A[Maxm], B[Maxm], C[Maxm];
vector <ii> neigh[Maxn];
bool tk[Maxn];
bool spec[Maxm];
int cur, tim[Maxn], low[Maxn];
int res = Inf;
int usda, usdb;

void Traverse1(int v)
{
	tk[v] = true;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i].first;
		if (!tk[u]) { 
			spec[neigh[v][i].second] = true; 
			Traverse1(u); 
		}
	}
}

void Traverse2(int v, int p, int forb, int used)
{
	tim[v] = low[v] = ++cur;
	bool pos = !tim[t];
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.second == p || u.second == forb) continue;
		if (!tim[u.first]) {
			Traverse2(u.first, u.second, forb, used);
			low[v] = min(low[v], low[u.first]);
			if (pos && tim[t] && tim[u.first] == low[u.first]) {
				if (used + C[u.second] < res) {
					res = used + C[u.second];
					usda = forb; usdb = u.second;
				}
			}
			pos = !tim[t];
		} else low[v] = min(low[v], tim[u.first]);
	}
	if (v == s && pos)
		if (used < res) {
			res = used;
			usda = forb; usdb = -1;
		}
}

int main()
{
	scanf("%d %d", &n, &m);
	scanf("%d %d", &s, &t);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &A[i], &B[i], &C[i]);
		neigh[A[i]].push_back(ii(B[i], i));
		neigh[B[i]].push_back(ii(A[i], i));
	}
	Traverse1(s);
	if (!tk[t]) {
		printf("0\n");
		printf("0\n");
		return 0;
	}
	for (int i = 1; i <= m; i++) if (spec[i]) {
		fill(tim, tim + n + 1, 0); cur = 0;
		Traverse2(s, 0, i, C[i]);
	}
	if (res == Inf) printf("-1\n");
	else {
		printf("%d\n", res);
		if (usdb == -1) {
			printf("1\n");
			printf("%d\n", usda);
		} else {
			printf("2\n");
			printf("%d %d\n", usda, usdb);
		}
	}
	return 0;
}