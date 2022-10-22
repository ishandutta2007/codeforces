#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef pair <int, char> ic;
typedef pair <int, int> ii;

const int Maxn = 105;
const int Maxl = 26;
const int Maxm = 1005;

int n, m;
vector <ic> neigh[Maxn];
int dp[Maxn][Maxn][Maxl];
bool tk[Maxn];
vector <int> seq;
int id[Maxn];
vector <ii> byid[Maxm];

void Traverse(int v)
{
	if (tk[v]) return;
	tk[v] = true;
	for (int i = 0; i < neigh[v].size(); i++)
		Traverse(neigh[v][i].first);
	id[v] = seq.size(); seq.push_back(v);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b; char c; scanf("%d %d %c", &a, &b, &c);
		neigh[a].push_back(ic(b, c));
	}
	for (int i = 1; i <= n; i++) if (!tk[i])
		Traverse(i);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			byid[id[i] + id[j]].push_back(ii(i, j));
	for (int i = 0; i < Maxm; i++)
		for (int j = 0; j < byid[i].size(); j++) {
			int a = byid[i][j].first, b = byid[i][j].second;
			for (int l = 0; l < Maxl; l++) {
				dp[a][b][l] = -1;
				for (int z = 0; z < neigh[a].size(); z++){
					int u = neigh[a][z].first;
					int let = neigh[a][z].second - 'a';
					if (let >= l && dp[b][u][let] == -1) { dp[a][b][l] = 1; break; }
				}
			}
		}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (dp[i][j][0] == 1) printf("A");
			else printf("B");
		printf("\n");
	}
	return 0;
}