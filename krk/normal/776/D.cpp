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
int r[Maxn];
int my[Maxn][2], pnt[Maxn];
vector <ii> neigh[Maxn];
int col[Maxn];

bool Fill(int v, int c)
{
	if (col[v] != -1)
		return col[v] == c;
	col[v] = c;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (!Fill(u.first, (c ^ u.second))) return false;
	}
	return true;
}

int main() 
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &r[i]);
		r[i] ^= 1;
	}
	for (int i = 1; i <= m; i++) {
		int x; scanf("%d", &x);
		while (x--) {
			int a; scanf("%d", &a);
			my[a][pnt[a]++] = i;
		}
	}
	fill(col, col + Maxn, -1);
	for (int i = 1; i <= n; i++) {
		neigh[my[i][0]].push_back(ii(my[i][1], r[i]));
		neigh[my[i][1]].push_back(ii(my[i][0], r[i]));
	}
	for (int i = 1; i <= m; i++) if (col[i] == -1)
		if (!Fill(i, 0)) { printf("NO\n"); return 0; }
	printf("YES\n");
    return 0;
}