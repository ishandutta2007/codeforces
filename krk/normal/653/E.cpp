#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;

set <ii> S;
int n, m, k;
int good[Maxn], par[Maxn];
vector <int> V[Maxn];
int gcnt;
set <int> G, B;

bool Check(int a, int b) { return S.find(ii(a, b)) != S.end(); }

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void Merge(int a, int b)
{
	good[a] |= good[b];
	for (int i = 0; i < V[b].size(); i++)
		V[a].push_back(V[b][i]);
	V[b].clear();
	par[b] = a;
}

void unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return;
	if (good[a] && good[b]) gcnt--;
	if (V[a].size() >= V[b].size()) Merge(a, b);
	else Merge(b, a);
}

bool tryIt(int comp, int me)
{
	for (int i = 0; i < V[comp].size(); i++)
		if (!Check(V[comp][i], me)) { unionSet(comp, me); return true; }
	return false;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		if (a > b) swap(a, b);
		S.insert(ii(a, b));
	}
	for (int i = 2; i <= n; i++)
		if (!Check(1, i)) {
			gcnt++; good[i] = true;
		}
	if (gcnt < k) { printf("impossible\n"); return 0; }
	for (int i = 2; i <= n; i++) {
		par[i] = i; 
		V[i].push_back(i);
	}
	for (int i = 2; i <= n; i++) {
		for (set <int>::iterator it = G.begin(); it != G.end() && (gcnt > k || !good[getPar(i)]); )
			if (tryIt(*it, i)) G.erase(it++);
			else it++;
		for (set <int>::iterator it = B.begin(); it != B.end(); )
			if (tryIt(*it, i)) B.erase(it++);
			else it++;
		if (good[getPar(i)]) G.insert(getPar(i));
		else B.insert(getPar(i));
	}
	if (G.size() == k && B.size() == 0) printf("possible\n");
	else printf("impossible\n");
	return 0;
}