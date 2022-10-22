#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];
int L[Maxn];
vector <int> seq;

void Traverse1(int v, int p = 0)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		L[u] = L[v] + 1;
		Traverse1(u, v);
	}
}

int Traverse2(int v, int p = 0)
{
	int best = 0;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		int cand = Traverse2(u, v) + 1;
		seq.push_back(min(best, cand));
		best = max(best, cand);
	}
	return best;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse1(1);
	int r = 1;
	for (int i = 1; i <= n; i++)
		if (L[i] > L[r]) r = i;
	seq.push_back(Traverse2(r));
	sort(seq.rbegin(), seq.rend());
	int cur = 1;
	for (int i = 0; i < n; i++) {
		printf("%d%c", cur, i + 1 < n? ' ': '\n');
		if (i < seq.size()) cur += seq[i];
	}
	return 0;
}