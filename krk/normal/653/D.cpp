#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

typedef long double ld;
typedef pair <int, int> ii;

const int Maxn = 52;
const int Maxm = 505;
const int Inf = 1000000;

int R[Maxn][Maxn];
int n, m, x;
int A[Maxm], B[Maxm], C[Maxm];
vector <int> neigh[Maxn];
int flow[Maxn], par[Maxn];

int getFlow()
{
	fill(flow, flow + Maxn, 0); flow[1] = Inf;
	priority_queue <ii> Q; Q.push(ii(flow[1], 1));
	while (!Q.empty()) {
		int f = Q.top().first, v = Q.top().second; Q.pop();
		if (v == n) break;
		if (flow[v] != f) continue;
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (min(f, R[v][u]) > flow[u]) {
				flow[u] = min(f, R[v][u]); par[u] = v;
				Q.push(ii(flow[u], u));
			}
		}
	}
	int res = flow[n];
	if (res == 0) return res;
	int v = n;
	while (v != 1) {
		int u = par[v];
		R[u][v] -= res; R[v][u] += res;
		v = u;
	}
	return res;
}

bool Possible(ld tot)
{
	fill((int*)R, (int*)R + Maxn * Maxn, 0);
	ld forone = tot / x;
	for (int i = 0; i < m; i++) {
		int tr = int(min(ld(Inf), C[i] / forone));
		R[A[i]][B[i]] += tr;
	}
	int mf = 0, f;
	while ((f = getFlow()) != 0) {
		mf += f;
		if (mf >= x) return true;
	}
	return false;
}

int main()
{
	scanf("%d %d %d", &n, &m, &x);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &A[i], &B[i], &C[i]);
		neigh[A[i]].push_back(B[i]);
		neigh[B[i]].push_back(A[i]);
	}
	ld lef = 0.0l, rig = 1000000000.0l;
	for (int i = 0; i < 65; i++) {
		ld mid = (lef + rig) / 2.0l;
		if (Possible(mid)) lef = mid;
		else rig = mid;
	}
	cout << fixed << setprecision(10) << lef << endl;
	return 0;
}