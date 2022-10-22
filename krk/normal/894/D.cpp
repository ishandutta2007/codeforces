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
typedef pair <ll, ll> llll;

const int Maxn = 2000006;
const int Maxq = 100005;

int n, m;
vector <ii> neigh[Maxn];
int L[Maxn];
int A[Maxq], H[Maxq];
int tims[Maxq];
ll sum[Maxq];
vector <ii> tk[Maxn];
vector <llll> V[Maxn];

void Insert(int v, int t, int quer, int forb)
{
	if (t > H[quer]) return;
	tims[quer]++; sum[quer] += t;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.first != forb && t + u.second <= H[quer])
			tk[u.first].push_back(ii(t + u.second, quer));
	}
	if (v > 1) Insert(v / 2, t + L[v], quer, v);
}

void Traverse(int v)
{
	for (int i = 0; i < neigh[v].size(); i++)
		Traverse(neigh[v][i].first);
	V[v].push_back(llll(0, 0));
	int lc = 2 * v, rc = 2 * v + 1;
	ll adda = lc <= n? neigh[v][0].second: 0;
	ll addb = rc <= n? neigh[v][1].second: 0;
	int i = 0, j = 0;
	while (i < V[lc].size() || j < V[rc].size())
		if (i < V[lc].size() && (j >= V[rc].size() || adda + V[lc][i].first < addb + V[rc][j].first)) {
			V[v].push_back(llll(adda + V[lc][i].first, V[v].back().second + adda + V[lc][i].first));
			i++;
		} else {
			V[v].push_back(llll(addb + V[rc][j].first, V[v].back().second + addb + V[rc][j].first));
			j++;
		}
	for (int i = 0; i < tk[v].size(); i++) {
		ii p = tk[v][i];
		ll lft = H[p.second] - p.first;
		int ind = lower_bound(V[v].begin(), V[v].end(), llll(lft + 1, 0)) - V[v].begin();
		tims[p.second] += ind; sum[p.second] += ll(ind) * p.first + V[v][ind - 1].second;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &L[i]);
		neigh[i / 2].push_back(ii(i, L[i]));
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &A[i], &H[i]);
		Insert(A[i], 0, i, -1);
	}
	Traverse(1);
	for (int i = 0; i < m; i++) {
		ll res = ll(H[i]) * tims[i] - sum[i];
		printf("%I64d\n", res);
	}
	return 0;
}