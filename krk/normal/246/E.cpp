#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

const int Maxn = 100005;

int n;
map <string, int> ID;
int nam[Maxn], r[Maxn];
vector <int> neigh[Maxn];
int y[Maxn], xmin[Maxn], xmax[Maxn], curx;
vector <int> inlvl[Maxn];
int m;
int V[Maxn], K[Maxn];
vector <int> que[Maxn];
map <int, int> res[Maxn];

int getID(const string &s)
{
	if (!ID.count(s)) ID[s] = ID.size() - 1;
	return ID[s];
}

void Traverse(int v, int lvl)
{
	y[v] = lvl; inlvl[lvl].push_back(v);
	if (neigh[v].size()) {
		for (int i = 0; i < neigh[v].size(); i++)
			Traverse(neigh[v][i], lvl + 1);
		xmin[v] = xmin[neigh[v][0]]; xmax[v] = xmax[neigh[v][neigh[v].size() - 1]];
	} else xmin[v] = xmax[v] = curx++;
}

bool Less(const int &a, const int &b) { return y[a] > y[b]; }

void Copy(set <int> &a, set <int> &b)
{
	for (set <int>::iterator it = a.begin(); it != a.end(); it++)
		b.insert(*it);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		string s; cin >> s >> r[i];
		nam[i] = getID(s);
		if (r[i]) neigh[r[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		if (!r[i]) Traverse(i, 0);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &V[i], &K[i]);
		if (y[V[i]] + K[i] < n) que[y[V[i]] + K[i]].push_back(V[i]);
	}
	for (int i = 0; i < n; i++) if (que[i].size()) {
		sort(que[i].begin(), que[i].end(), Less);
		map <int, set <int> > M;
		for (int j = 0; j < inlvl[i].size(); j++) {
			int v = inlvl[i][j];
			set <int> S; S.insert(nam[v]);
			M[xmin[v]] = S;
		}
		for (int j = 0; j < que[i].size(); j++) {
			int v = que[i][j];
			map <int, set <int> >::iterator itl, itm, itr;
			itl = M.lower_bound(xmin[v]);
			itr = M.upper_bound(xmax[v]);
			if (itl == itr) { res[v][i] = 0; continue; }
			itm = itl; itm++;
			while (itm != itr)
				if (itl->second.size() <= itm->second.size()) {
					Copy(itl->second, itm->second);
					M.erase(itl++); itm++;
				} else {
					Copy(itm->second, itl->second);
					M.erase(itm++);
				}
			res[v][i] = itl->second.size();
		}
	}
	for (int i = 0; i < m; i++)
		if (y[V[i]] + K[i] >= n) printf("0\n");
		else printf("%d\n", res[V[i]][y[V[i]] + K[i]]);
	return 0;
}