#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;

int n, m, k;
vector <ii> neigh[Maxn];
map <string, int> ID;
int room[Maxn];
bool unlock1[Maxn];
bool keys1[Maxn][Maxn], peop1[Maxn][Maxn];
bool unlock2[Maxn];
bool keys2[Maxn][Maxn], peop2[Maxn][Maxn];

int getID(const string &s)
{
	if (!ID.count(s)) ID[s] = ID.size();
	return ID[s];
}

void dfsKey(int v, int room, bool keys[][Maxn], bool unlock[]);

void Unlock(int a, int b, bool keys[][Maxn], bool unlock[])
{
	for (int i = 1; i <= m; i++)
		if (keys[i][a] && !keys[i][b]) dfsKey(i, b, keys, unlock);
		else if (!keys[i][a] && keys[i][b]) dfsKey(i, a, keys, unlock);
}

void dfsKey(int v, int room, bool keys[][Maxn], bool unlock[])
{
	if (keys[v][room]) return;
	keys[v][room] = true;
	for (int i = 0; i < neigh[room].size(); i++) {
		ii u = neigh[room][i];
		if (v == u.second && !unlock[v]) { unlock[v] = true; Unlock(room, u.first, keys, unlock); }
		if (unlock[u.second]) dfsKey(v, u.first, keys, unlock);
	}
}

void dfsPeop(int v, int room, bool peop[][Maxn], bool unlock[])
{
	if (peop[v][room]) return;
	peop[v][room] = true;
	for (int i = 0; i < neigh[room].size(); i++) {
		ii u = neigh[room][i];
		if (unlock[u.second]) dfsPeop(v, u.first, peop, unlock);
	}
}

void Solve(bool unlock[], bool keys[][Maxn], bool peop[][Maxn])
{
	for (int i = 1; i <= k; i++) {
		string nam; int rm, cnt; cin >> nam >> rm >> cnt;
		room[getID(nam)] = rm;
		while (cnt--) {
			int num; scanf("%d", &num);
			dfsKey(num, rm, keys, unlock);
		}
	}
	for (int i = 1; i <= k; i++)
		dfsPeop(i, room[i], peop, unlock);
}

bool Match()
{
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (keys1[i][j] != keys2[i][j]) return false;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++)
			if (peop1[i][j] != peop2[i][j]) return false;
	return true;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(ii(b, i)); neigh[b].push_back(ii(a, i));
	}
	Solve(unlock1, keys1, peop1); Solve(unlock2, keys2, peop2);
	printf("%s\n", Match()? "YES": "NO");
	return 0;
}