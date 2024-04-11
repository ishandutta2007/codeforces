#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];
int P[Maxn], L[Maxn], cnt[Maxn];
int par[Maxn], ind[Maxn];
vector <ii> seq[Maxn];
int q;
int k, got[Maxn], wh[Maxn];
set <ii> Q;
int res;

void Traverse1(int v)
{
	cnt[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (P[v] == u) continue;
		P[u] = v; L[u] = L[v] + 1;
		Traverse1(u);
		cnt[v] += cnt[u];
	}
}

void Traverse2(int v, int mypar, int myind)
{
	par[v] = mypar; ind[v] = myind;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (P[v] == u) continue;
		if (cnt[u] > cnt[v] / 2) Traverse2(u, mypar, myind + 1);
		else Traverse2(u, u, 0);
	}
}

bool Pos()
{
	set <int> S;
	for (int i = 0; i < k; i++)
		S.insert(got[i]);
	for (int i = 0; i < k; i++)
		if (S.find(P[got[i]]) != S.end())
			return false;
	return true;
}

void Pop(int v)
{
	ii p = seq[v].back(); seq[v].pop_back();
	p.second = abs(p.second);
	Q.erase(ii(L[par[wh[p.second]]], p.second));
}

void Fix(int v)
{
	sort(seq[v].begin(), seq[v].end());
	while (seq[v].size() > 1) {
		int val = seq[v].back().first;
		int i = seq[v].size() - 1;
		while (i >= 0 && seq[v][i].first == val) i--;
		i++;
		if (i != seq[v].size() - 1)
			if (seq[v][i].second < 0)
				while (i != seq[v].size() - 1) { res++; Pop(v); }
			else {
				res++;
				while (i != seq[v].size()) Pop(v);
			}
		else {
			int j = seq[v].size() - 2;
			int val2 = seq[v][j].first;
			while (j >= 0 && seq[v][j].first == val2) j--;
			j++;
			if (seq[v][j].second < 0)
				while (j != seq[v].size() - 1) { res++; Pop(v); }
			else {
				res++;
				while (j != seq[v].size()) Pop(v);
			}
		}
	}
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
	Traverse2(1, 1, 0);
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			scanf("%d", &got[i]);
			wh[got[i]] = got[i];
		}
		if (!Pos()) { printf("-1\n"); continue; }
		
		Q.clear();
		for (int i = 0; i < k; i++) {
			seq[par[got[i]]].push_back(ii(ind[got[i]], -got[i]));
			Q.insert(ii(L[par[got[i]]], got[i]));
		}
		res = 0;
		while (!Q.empty()) {
			set <ii>::iterator it = Q.end(); it--; 
			int v = it->second; Q.erase(it);
			if (seq[par[wh[v]]].size() > 1) {
				Q.insert(ii(L[par[wh[v]]], v));
				Fix(par[wh[v]]); continue;
			} else {
				seq[par[wh[v]]].pop_back();
				if (L[par[wh[v]]]) {
					wh[v] = P[par[wh[v]]];
					seq[par[wh[v]]].push_back(ii(ind[wh[v]], v));
					Q.insert(ii(L[par[wh[v]]], v));
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}