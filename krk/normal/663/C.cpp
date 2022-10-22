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

typedef pair <int, int> ii;

const int Maxn = 100005;

int n, m;
int u[Maxn], v[Maxn];
char c[Maxn];
vector <ii> neigh[Maxn];
int col[Maxn];
vector <int> my, res;
vector <int> has[2];
bool found;

bool Traverse(int v, int c, int i1, int i2)
{
	if (col[v] == c) return true;
	if (col[v] >= 0 && col[v] != c) return false;
	col[v] = c; has[i1].push_back(v);
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.second) {
			if (!Traverse(u.first, 1 - c, i2, i1)) return false;
		} else if (!Traverse(u.first, c, i1, i2)) return false;
	}
	return true;
}

void Add(int a, int b, int c)
{
	neigh[a].push_back(ii(b, c));
	neigh[b].push_back(ii(a, c));
}

bool Get(char need)
{
	for (int i = 1; i <= n; i++) {
		neigh[i].clear(); col[i] = -1;
	}
	for (int i = 0; i < m; i++)
		Add(u[i], v[i], need != c[i]);
	my.clear();
	for (int i = 1; i <= n; i++) if (col[i] < 0) {
		has[0].clear(); has[1].clear();
		if (!Traverse(i, 0, 0, 1)) return false;
		int ind = has[0].size() <= has[1].size()? 0: 1;
		for (int j = 0; j < has[ind].size(); j++)
			my.push_back(has[ind][j]);
	}
	return true;
}

int main() 
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d %d %c", &u[i], &v[i], &c[i]);
	if (Get('B')) { found = true; res = my; }
	if (Get('R') && (!found || my.size() < res.size())) { found = true; res = my; }
	if (!found) printf("-1\n");
	else {
		printf("%d\n", res.size());
		for (int i = 0; i < res.size(); i++)
			printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	}
    return 0;
}