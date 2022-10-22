#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 300005;

struct pos {
	map <int, int> M;
	int add;
	pos() { M.clear(); add = 0; }
};

int n, m;
vector <int> neigh[Maxn];
pos P[Maxn];
int my[Maxn], L[Maxn];
ll res;

void Traverse1(int v, int p = 0)
{
	my[v] = v;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		L[u] = L[v] + 1;
		Traverse1(u, v);
	}
}

void Insert(pos &P, int lvl, int val)
{
	val -= P.add;
	map <int, int>::iterator it = P.M.upper_bound(lvl);
	if (it != P.M.begin()) {
		it--;
		if (it->second <= val) return;
		if (it->first != lvl) it++;
	}
	while (it != P.M.end() && val <= it->second)
		P.M.erase(it++);
	P.M[lvl] = val;
}

void Merge(pos &A, pos &B)
{
	for (map <int, int>::iterator it = B.M.begin(); it != B.M.end(); it++)
		Insert(A, it->first, it->second + B.add);
}

bool Calc(int v, int p = 0)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		if (!Calc(u, v)) return false;
		if (P[my[v]].M.size() >= P[my[u]].M.size()) Merge(P[my[v]], P[my[u]]);
		else { Merge(P[my[u]], P[my[v]]); my[v] = my[u]; }
	}
	if (v == 1) return true;
	map <int, int>::iterator lst = P[my[v]].M.end();
	while (lst != P[my[v]].M.begin()) {
		lst--;
		if (L[v] <= lst->first) { P[my[v]].M.erase(lst); lst = P[my[v]].M.end(); }
		else { lst++; break; }
	}
	if (lst == P[my[v]].M.begin()) return false;
	lst--;
	res += lst->second + P[my[v]].add; P[my[v]].add -= (lst->second + P[my[v]].add);
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse1(1);
	for (int i = 0; i < m; i++) {
		int v, u, c; scanf("%d %d %d", &v, &u, &c);
		Insert(P[my[v]], L[u], c);
	}
	if (!Calc(1)) printf("-1\n");
	else printf("%I64d\n", res);
	return 0;
}