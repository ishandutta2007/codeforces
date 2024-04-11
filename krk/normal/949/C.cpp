#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n, m, h;
int u[Maxn];
vector <int> neigh[Maxn], gneigh[Maxn];
vector <int> S;
bool onStack[Maxn];
int cur, low[Maxn], tim[Maxn];
int my[Maxn];
vector <vector <int> > seq;
bool from[Maxn];

void Fill(int v)
{
	cur++; low[v] = tim[v] = cur;
	S.push_back(v);
	onStack[v] = true;
	for (int i = 0; i < neigh[v].size(); i++) {
		int b = neigh[v][i];
		if ((u[v] + 1) % h == u[b])
			if (!tim[b]) {
				Fill(b);
				low[v] = min(low[v], low[b]);
			} else if (onStack[b]) low[v] = min(low[v], tim[b]);
	}
	if (low[v] == tim[v]) {
		seq.push_back(vector <int>());
		int w;
		do {
			w = S.back(); S.pop_back(); onStack[w] = false;
			seq.back().push_back(w); my[w] = int(seq.size()) - 1;
		} while (w != v);
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &h);
	for (int i = 1; i <= n; i++)
		scanf("%d", &u[i]);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		bool was = false;
		for (int j = 0; j < neigh[i].size() && !was; j++) {
			int b = neigh[i][j];
			was = (u[i] + 1) % h == u[b];
		}
		if (!was) { printf("1\n%d\n", i); return 0; }
	}
	for (int i = 1; i <= n; i++) if (!tim[i])
		Fill(i);
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j < neigh[i].size(); j++) {
			int b = neigh[i][j];
			if ((u[i] + 1) % h == u[b] && my[i] != my[b]) from[my[i]] = true; 
		}
	int bi = 0;
	while (from[bi]) bi++;
	for (int i = 0; i < seq.size(); i++) 
		if (!from[i] && seq[i].size() < seq[bi].size())
			bi = i;
	printf("%d\n", seq[bi].size());
	for (int i = 0; i < seq[bi].size(); i++)
		printf("%d%c", seq[bi][i], i + 1 < seq[bi].size()? ' ': '\n');
	return 0;
}