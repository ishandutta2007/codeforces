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

const int Maxn = 100005;

int n, m;
vector <int> W[Maxn];
vector <int> neigh[Maxn];
vector <int> st;
bool tk[Maxn];

void Fill(int v)
{
	if (tk[v]) return;
	tk[v] = true;
	for (int i = 0; i < neigh[v].size(); i++)
		Fill(neigh[v][i]);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int cnt; scanf("%d", &cnt);
		W[i].resize(cnt);
		for (int j = 0; j < cnt; j++)
			scanf("%d", &W[i][j]);
	}
	for (int i = 1; i < n; i++) {
		int p = 0;
		while (p < W[i - 1].size() && p < W[i].size() && W[i - 1][p] == W[i][p]) p++;
		if (p == W[i - 1].size()) continue;
		if (p == W[i].size()) { printf("No\n"); return 0; }
		if (W[i - 1][p] < W[i][p]) neigh[W[i][p]].push_back(W[i - 1][p]);
		else { st.push_back(W[i - 1][p]); neigh[W[i][p]].push_back(0); }
	}
	for (int i = 0; i < st.size(); i++)
		Fill(st[i]);
	if (tk[0]) printf("No\n");
	else {
		vector <int> res;
		for (int i = 1; i <= m; i++)
			if (tk[i]) res.push_back(i);
		printf("Yes\n");
		printf("%d\n", res.size());
		for (int i = 0; i < res.size(); i++)
			printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	}
	return 0;
}