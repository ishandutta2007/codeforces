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

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 1000005;

int n, m;
vector <ii> neigh[Maxn];
int cur, tim[Maxn], low[Maxn];
vector <int> S;
bool onStack[Maxn];
int comp, incomp[Maxn];
vector <ii> cneigh[Maxn]; 
ll valcomp[Maxn];
ll res[Maxn];
int s;

void Connect(int v)
{
	tim[v] = low[v] = ++cur;
	S.push_back(v);
	onStack[v] = true;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i].first;
		if (!tim[u]) {
			Connect(u);
			low[v] = min(low[v], low[u]);
		} else if (onStack[u])
			low[v] = min(low[v], tim[u]);
	}
	if (low[v] == tim[v]) {
		comp++;
		int w;
		do {
			w = S.back(); S.pop_back();
			onStack[w] = false;
			incomp[w] = comp;
		} while (w != v);
	}
}

ll Solve(int v)
{
	if (res[v] < 0) {
		ll mx = 0;
		for (int i = 0; i < cneigh[v].size(); i++) {
			ii u = cneigh[v][i];
			mx = max(mx, u.second + Solve(u.first));
		}
		res[v] = mx + valcomp[v];
	}
	return res[v];
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y, w; scanf("%d %d %d", &x, &y, &w);
		neigh[x].push_back(ii(y, w));
	}
	for (int i = 1; i <= n; i++) if (!tim[i])
		Connect(i);
	vector <int> seq;
	vector <ll> sum;
	ll sm = 0;
	for (int i = 1; i <= 20005; i++) {
		seq.push_back(i * (i - 1) / 2);
		sm += seq.back();
		sum.push_back(sm);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < neigh[i].size(); j++) {
			ii u = neigh[i][j];
			if (incomp[i] == incomp[u.first]) {
				int ind = upper_bound(seq.begin(), seq.end(), u.second) - seq.begin();
				valcomp[incomp[i]] += ll(ind) * u.second - sum[ind - 1]; 
			} else cneigh[incomp[i]].push_back(ii(incomp[u.first], u.second));
		}
	fill(res, res + Maxn, -1ll);
	scanf("%d", &s);
	printf("%I64d\n", Solve(incomp[s]));
	return 0;
}