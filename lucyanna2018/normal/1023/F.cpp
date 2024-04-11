#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

#define ran 500500
int N, M1, M2;
int ace[ran];int ancestor(int x) {return x - ace[x] ? ace[x] = ancestor(ace[x]) : x;}
vector<tuple<int, int, int> > alle, alle2;

vector<pair<int, int> > e[ran];

namespace LCA {

#define pw 20

	int ff[ran][pw], dep[ran];

	void dfs(int cur, int fat, int d) {
		dep[cur] = d;

		ff[cur][0] = fat;
		for (int i = 1;i < pw;i++)
			ff[cur][i] = ff[ff[cur][i - 1]][i - 1];

		for (int i = 0;i < (int)e[cur].size();i++) {
			int nxt = e[cur][i].first;
			if (nxt == fat) continue;
			dfs(nxt, cur, d + 1);
		}
	}

	int ace(int x, int d) {
		for (int i = 0; (1 << i) <= d; i++)
			if (d&(1 << i)) x = ff[x][i];
		return x;
	}

	int lca(int x, int y) {
		int dx = dep[x], dy = dep[y];
		if (dx > dy) x = ace(x, dx - dy);
		if (dy > dx) y = ace(y, dy - dx);
		if (x == y) return x;

		for (int i = pw - 1;i >= 0;i--)
			if (ff[x][i] != ff[y][i]) {
				x = ff[x][i]; y = ff[y][i];
			}
		return ff[x][0];
	}

}

vector<int> ins[ran], era[ran];
multiset<int> EE[ran], *ee[ran];long long int res;bool inf;
void merge(multiset<int>*&A, multiset<int>*&B) {
	if (B->size() < A->size()) {
		for (auto w : *B) {
			A->insert(w);
		}
		B->clear();
	}
	else {
		for (auto w : *A)
			B->insert(w);
		A->clear();
		A = B;
	}
}
void my_dfs(int x, int fat) {
	ee[x] = &EE[x];
	for (auto it : e[x]) {
		int y = it.first;
		if (y == fat)continue;
		my_dfs(y, x);
		if (it.second == -1) {
			if (ee[y]->empty())inf = true;else {
				res += *(ee[y]->begin());
			}
		}
		merge(ee[x], ee[y]);
	}
	for (auto z : era[x]) {
		ee[x]->erase(ee[x]->find(z));
	}
	for (auto z : ins[x]) {
		ee[x]->insert(z);
	}
}

int main() {
	int M1, M2;
	scanf("%d%d%d", &N, &M1, &M2);
	for (int i = 1; i <= N; i++)ace[i] = i;
	for (int i = 0; i < M1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(make_pair(y, -1));
		e[y].push_back(make_pair(x, -1));
		ace[ancestor(x)] = ancestor(y);
	}
	for (int i = 0; i < M2; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		alle.push_back(make_tuple(z, x, y));
	}
	sort(alle.begin(), alle.end());
	for (auto it : alle) {
		int x = get<1>(it), y=get<2>(it), z = get<0>(it);
		if (ancestor(x) != ancestor(y)) {
			e[x].push_back(make_pair(y, z));
			e[y].push_back(make_pair(x, z));
			ace[ancestor(x)] = ancestor(y);
		}
		else {
			alle2.push_back(it);
		}
	}
	LCA::dfs(1, 1, 0);
	for (auto it : alle2) {
		int x = get<1>(it), y = get<2>(it), z = get<0>(it);
		int w = LCA::lca(x, y);
		if (x != w) {
			ins[x].push_back(z);
			era[w].push_back(z);
		}
		if (y != w) {
			ins[y].push_back(z);
			era[w].push_back(z);
		}
	}

	res = inf = false;
	my_dfs(1, 1);
	cout << (inf ? -1 : res) << endl;
	return 0;
}