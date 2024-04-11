#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 1000005;

int n, m;
int p[Maxn];
vector <int> neigh[Maxn];
bool tk[Maxn];
vector <int> cur, seq;

void Fill(int v)
{
	if (tk[v]) return;
	tk[v] = true; cur.push_back(v);
	for (int i = 0; i < neigh[v].size(); i++)
		Fill(neigh[v][i]);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) if (!tk[i]) {
		Fill(i);
		for (int j = 0; j < cur.size(); j++)
			seq.push_back(p[cur[j]]);
		sort(cur.begin(), cur.end());
		sort(seq.rbegin(), seq.rend());
		for (int j = 0; j < cur.size(); j++)
			p[cur[j]] = seq[j];
		cur.clear(); seq.clear();
	}
	for (int i = 1; i <= n; i++)
		printf("%d%c", p[i], i + 1 <= n? ' ': '\n');
	return 0;
}