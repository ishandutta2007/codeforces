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
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 205;
const int Maxm = 300005;
const int Inf = 1000000000;

bool prime[Maxm];
int n, k;
int p[Maxn], c[Maxn], l[Maxn];
int N;
int R[Maxn][Maxn];
vector <int> neigh[Maxn];
int flow[Maxn], par[Maxn];

void addEdge(int a, int b, int cap)
{
	neigh[a].push_back(b); neigh[b].push_back(a);
	R[a][b] = cap;
}

int getFlow()
{
	fill(flow, flow + N, 0); flow[0] = Inf;
	priority_queue <ii> Q; Q.push(ii(Inf, 0));
	while (!Q.empty()) {
		int v = Q.top().second, f = Q.top().first; Q.pop();
		if (f != flow[v]) continue;
		if (v == N - 1) break;
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (min(f, R[v][u]) > flow[u]) {
				flow[u] = min(f, R[v][u]); par[u] = v;
				Q.push(ii(flow[u], u));
			}
		}
	}
	int v = N - 1;
	int res = flow[v];
	if (!res) return 0;
	while (v) {
		int u = par[v];
		R[u][v] -= res; R[v][u] += res;
		v = u;
	}
	return res;
}

int Get(int lvl)
{
	int sumones = 0, mxones = -1;
	int sum = 0;
	vector <ii> A, B;
	for (int i = 0; i < n; i++)
		if (lvl >= l[i]) {
			sum += p[i];
			if (c[i] == 1) {
				sumones += p[i];
				if (mxones == -1 || p[i] > p[mxones]) mxones = i;
			} else if (c[i] % 2) A.push_back(ii(c[i], p[i]));
				   else B.push_back(ii(c[i], p[i]));
		}
	if (mxones != -1) {
		sum = sum - sumones + p[mxones];
		A.push_back(ii(1, p[mxones]));
	}
	N = 2 + A.size() + B.size();
	for (int i = 0; i < N; i++) {
		neigh[i].clear();
		for (int j = 0; j < N; j++)
			R[i][j] = 0;
	}
	for (int i = 0; i < A.size(); i++)
		addEdge(0, i + 1, A[i].second);
	for (int i = 0; i < B.size(); i++)
		addEdge(A.size() + i + 1, N - 1, B[i].second);
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B.size(); j++)
			if (prime[A[i].first + B[j].first]) 
				addEdge(i + 1, A.size() + j + 1, Inf);
	int f;
	while ((f = getFlow()) != 0) sum -= f;
	return sum;
}

int main()
{
	fill(prime + 2, prime + Maxm, true);
	for (int i = 2; i < Maxm; i++) if (prime[i])
		for (int j = i + i; j < Maxm; j += i) prime[j] = false;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &p[i], &c[i], &l[i]);
	int lef = 1, rig = 105, res = -1;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (Get(mid) >= k) { res = mid; rig = mid - 1; }
		else lef = mid + 1;
	}
	printf("%d\n", res);
	return 0;
}