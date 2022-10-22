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

const int Maxn = 200005;

int n, m;
map <int, int> neigh[Maxn];
int seq[Maxn];
bool tk[Maxn];
vector <int> res;

bool Less(const int &a, const int &b)
{
	return neigh[a].size() < neigh[b].size();
}

void Add(int v, int u)
{
	tk[u] = true;
	for (map <int, int>::iterator it = neigh[u].begin(); it != neigh[u].end(); it++) {
		map <int, int>::iterator it2 = neigh[v].find(it->first);
		if (it2 != neigh[v].end()) it2->second += it->second;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d %d", &x, &y);
		neigh[x][y]++; neigh[y][x]++;
	}
	for (int i = 1; i <= n; i++)
		seq[i - 1] = i;
	sort(seq, seq + n, Less);
	for (int i = 0; i < n; i++) {
		int v = seq[i];
		if (tk[v]) continue;
		tk[v] = true;
		int cnt = 1;
		int pnt = 1;
		for (map <int, int>::iterator it = neigh[v].begin(); it != neigh[v].end(); it++) {
			while (pnt < it->first) {
				if (pnt != v) { Add(v, pnt); tk[pnt] = true; cnt++; }
				pnt++;
			}
			pnt++;
		}
		while (pnt <= n) {
			if (pnt != v) { Add(v, pnt); tk[pnt] = true; cnt++; }
			pnt++;
		}
		bool upd = true;
		while (upd) {
			upd = false;
			for (map <int, int>::iterator it = neigh[v].begin(); it != neigh[v].end(); )
				if (it->second < cnt) { upd = true; Add(v, it->first); tk[it->first] = true; cnt++; neigh[v].erase(it++); }
				else it++;
		}
		res.push_back(cnt);
	}
	sort(res.begin(), res.end());
	printf("%d\n", int(res.size()));
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}