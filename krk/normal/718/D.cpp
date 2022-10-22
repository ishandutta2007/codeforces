#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;
const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int val1 = 857;
const int val2 = 557;
const int arg1 = 1000033;
const int arg2 = 1000211;

int n;
vector <int> neigh[Maxn];
ii dp[Maxn];
set <ii> S;

ii Combine(vector <ii> &V, int deg)
{
	sort(V.begin(), V.end());
	ii res = ii(0, 0);
	for (int i = 0; i < V.size(); i++) {
		res.first = (ll(res.first) * arg1 + ll(i + 1) * V[i].first) % mod1;
		res.second = (ll(res.second) * arg2 + ll(i + 1) * V[i].second) % mod2;
	}
	res.first = (ll(res.first) * arg1 + ll(deg) * val1) % mod1;
	res.second = (ll(res.second) * arg2 + ll(deg) * val2) % mod2;
	return res;
}

void Traverse(int v, int p = 0)
{
	vector <ii> got;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v);
		got.push_back(dp[u]);
	}
	dp[v] = Combine(got, int(neigh[v].size()) + bool(p == 0));
}

void Traverse2(int v, int p, vector <ii> &ft)
{
	vector <ii> tmp = ft;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		ft.push_back(dp[u]);
	}
	if (neigh[v].size() < 4)
		S.insert(Combine(ft, int(neigh[v].size()) + 1));
	ft = tmp;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		for (int j = 0; j < neigh[v].size(); j++) {
			int z = neigh[v][j];
			if (z == p || z == u) continue;
			ft.push_back(dp[z]);
		}
		vector <ii> nw; nw.push_back(Combine(ft, int(neigh[v].size())));
		Traverse2(u, v, nw);
		ft = tmp;
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
	Traverse(1);
	vector <ii> empty; Traverse2(1, 0, empty);
	printf("%d\n", int(S.size()));
	return 0;
}