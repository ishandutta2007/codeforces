#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int X[Maxn], Y[Maxn], W[Maxn], P[Maxn];
vector <int> neigh[Maxn];
ll sum[Maxn];
int cur, lef[Maxn], rig[Maxn];
ll BIT[Maxn];
deque <int> D[Maxn];
int par[Maxn];

void Update(int ind, ll val)
{
	for (int i = ind; i <= n; i += i & -i)
		BIT[i] += val;
}

ll Get(int ind)
{
	ll res = 0;
	for (int i = ind; i > 0; i -= i & -i)
		 res += BIT[i];
	return res;
}

ll Held(int v)
{
	return Get(rig[v]) - Get(lef[v] - 1);
}

void Traverse(int v)
{
	lef[v] = ++cur; Update(lef[v], sum[v]);
	for (int i = 0; i < neigh[v].size(); i++) {
		int ind = neigh[v][i];
		Traverse(Y[ind]);
	}
	rig[v] = cur;
}

void Merge(int a, int b)
{
	for (int i = 0; i < D[par[b]].size(); i++)
		D[par[a]].push_back(D[par[b]][i]);
	D[par[b]].clear(); par[b] = par[a];
}

bool Solve(int v)
{
	par[v] = v;
	for (int i = 0; i < neigh[v].size(); i++) {
		int ind = neigh[v][i];
		if (!Solve(Y[ind])) return false;
		ll val;
		while ((val = Held(Y[ind])) > P[ind]) {
			if (D[par[Y[ind]]].size() == 0) return false;
			int u = D[par[Y[ind]]][0];
			ll got = min(ll(W[u] - 1), P[u] - Held(Y[u]));
			ll tk = min(got, val - P[ind]);
			W[u] -= tk; P[u] -= tk; Update(lef[X[u]], -tk);
			if (got == tk) D[par[Y[ind]]].pop_front();
		}
		if (D[par[v]].size() >= D[par[Y[ind]]].size()) Merge(v, Y[ind]);
		else Merge(Y[ind], v);
		D[par[v]].push_back(ind);
	}
	return true;
}

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d %d %d", &X[i], &Y[i], &W[i], &P[i]);
		neigh[X[i]].push_back(i); sum[X[i]] += W[i];
	}
	Traverse(1);
	if (Solve(1)) {
		printf("%d\n", n);
		for (int i = 0; i < n - 1; i++)
			printf("%d %d %d %d\n", X[i], Y[i], W[i], P[i]);
	} else printf("-1\n");
    return 0;
}