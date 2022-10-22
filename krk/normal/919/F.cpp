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

const int Maxn = 300005;
const int Maxd = 5;

struct pos {
	int A[Maxd], B[Maxd];
	bool operator <(const pos &b) const {
		for (int i = 0; i < Maxd; i++)
			if (A[i] != b.A[i]) return A[i] < b.A[i];
		for (int i = 0; i < Maxd; i++)
			if (B[i] != b.B[i]) return B[i] < b.B[i];
		return false;
	}
	bool operator ==(const pos &b) const {
		for (int i = 0; i < Maxd; i++)
			if (A[i] != b.A[i] || B[i] != b.B[i]) return false;
		return true;
	}
};

map <pos, int> M;
vector <int> neigh[Maxn];
int in[Maxn];
int st[Maxn];
int seq[Maxn], slen;
int t;

void addEdge(int a, int b)
{
	neigh[a].push_back(b); in[b]++;
}

int getID(const pos &p)
{
	map <pos, int>::iterator it = M.find(p);
	if (it == M.end()) {
		int res = M.size(); M[p] = res;
		return res;
	}
	return it->second;
}

void getEdges(const pos &p)
{
	int v = getID(p);
	if (p.B[0] == 8) { st[v] = -1; seq[slen++] = v; }
	pos u;
	for (int i = 0; i < Maxd; i++) {
		u.A[i] = p.B[i]; u.B[i] = p.A[i];
	}
	for (int i = 1; i < Maxd; i++) if (p.A[i])
		for (int j = 1; j < Maxd; j++) if (p.B[j]) {
			int k = (i + j) % 5;
			u.B[i]--; u.B[k]++;
			addEdge(getID(u), v);
			u.B[i]++; u.B[k]--;
		}
}

void genB(int lvl, int lft, pos &p)
{
	if (lvl >= Maxd - 1) {
		p.B[lvl] = lft;
		getEdges(p);
	} else for (int i = 0; i <= lft; i++) {
		p.B[lvl] = i; genB(lvl + 1, lft - i, p);
	}
}

void genA(int lvl, int lft, pos &p)
{
	if (lvl >= Maxd - 1) { p.A[lvl] = lft; genB(0, 8, p); }
	else for (int i = 0; i <= lft; i++) {
		p.A[lvl] = i; genA(lvl + 1, lft - i, p);
	}
}

int main()
{
	pos p;
	genA(0, 8, p);
	for (int i = 0; i < slen; i++) {
		int v = seq[i];
		if (st[v] == -1)
			for (int j = 0; j < neigh[v].size(); j++) {
				int u = neigh[v][j];
				if (st[u] == 0) { st[u] = 1; seq[slen++] = u; }
			}
		else if (st[v] == 1)
			for (int j = 0; j < neigh[v].size(); j++) {
				int u = neigh[v][j];
				if (--in[u] == 0 && st[u] == 0) {
					st[u] = -1; seq[slen++] = u;
				}
			}
	}
	scanf("%d", &t);
	while (t--) {
		int f; scanf("%d", &f);
		fill(p.A, p.A + Maxd, 0); fill(p.B, p.B + Maxd, 0);
		for (int i = 0; i < 8; i++) {
			int a; scanf("%d", &a);
			p.A[a]++;
		}
		for (int i = 0; i < 8; i++) {
			int b; scanf("%d", &b);
			p.B[b]++;
		}
		if (f == 0) {
			int res = st[getID(p)];
			if (res == 1) printf("Alice\n");
			else if (res == -1) printf("Bob\n");
			else printf("Deal\n");
		} else {
			for (int i = 0; i < Maxd; i++)
				swap(p.A[i], p.B[i]);
			int res = st[getID(p)];
			if (res == 1) printf("Bob\n");
			else if (res == -1) printf("Alice\n");
			else printf("Deal\n");
		}
	}
	return 0;
}