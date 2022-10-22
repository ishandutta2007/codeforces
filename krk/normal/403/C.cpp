#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 2005;

int n;
vector <int> neigh[Maxn], rneigh[Maxn];
bool taken[Maxn];

void DFS(int v, vector <int> neigh[])
{
	if (taken[v]) return;
	taken[v] = true;
	for (int i = 0; i < neigh[v].size(); i++)
		DFS(neigh[v][i], neigh);
}

bool Check(vector <int> neigh[])
{
	fill(taken + 1, taken + n + 1, false);
	DFS(1, neigh);
	for (int i = 1; i <= n; i++)
		if (!taken[i]) return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int a; scanf("%d", &a);
			if (a) {
				neigh[i].push_back(j);
				rneigh[j].push_back(i);
			}
		}
	printf("%s\n", Check(neigh) && Check(rneigh)? "YES": "NO");
	return 0;
}