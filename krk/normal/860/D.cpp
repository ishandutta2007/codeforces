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
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 200005;

struct pos {
	int a, b, c;
	pos(int a = 0, int b = 0, int c = 0): a(a), b(b), c(c) {}
};

int n, m;
vector <int> neigh[Maxn];
int tk[Maxn];
vector <pos> res;

int Traverse(int v)
{
	tk[v] = 1;
	vector <int> seq;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (tk[u] == 1) continue;
		if (tk[u] == 2) seq.push_back(u);
		else {
			int z = Traverse(u);
			if (z != -1) res.push_back(pos(v, u, z));
			else seq.push_back(u);
		}
	}
	while (seq.size() >= 2) {
		res.push_back(pos(seq.back(), v, seq[int(seq.size()) - 2]));
		seq.pop_back(); seq.pop_back();
	}
	tk[v] = 2;
	return seq.empty()? -1: seq[0];
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) if (!tk[i])
		Traverse(i);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d %d %d\n", res[i].a, res[i].b, res[i].c);
	return 0;
}