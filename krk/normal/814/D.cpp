#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long double ld;
typedef long long ll;

const int Maxn = 1005;
const int Inf = 1000000000;

int n;
int X[Maxn], Y[Maxn], R[Maxn];
int par[Maxn], rad[Maxn];
vector <int> neigh[Maxn];
ld dp[Maxn][2][2];

void Traverse(int v)
{
	for (int i = 0; i < neigh[v].size(); i++)
		Traverse(neigh[v][i]);
	for (int a = 0; a < 2; a++)
		for (int b = 0; b < 2; b++) {
			dp[v][a][b] = -1e30l;
			for (int c = 0; c < 2; c++) {
				int na = a, nb = b;
				ld res = 0;
				if (c == 0) {
					res = a? ll(R[v]) * R[v]: -ll(R[v]) * R[v];
					na = 1 - na;
				} else {
					res = b? ll(R[v]) * R[v]: -ll(R[v]) * R[v];
					nb = 1 - nb;
				}
				for (int i = 0; i < neigh[v].size(); i++) {
					int u = neigh[v][i];
					res += dp[u][na][nb];
				}
				dp[v][a][b] = max(dp[v][a][b], res);
			}
		}
}

ll distS(ll ax, ll ay) { return ax * ax + ay * ay; }

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &X[i], &Y[i], &R[i]);
	fill(rad, rad + n, Inf);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) if (i != j && R[i] > R[j] && R[i] < rad[j])
			if (distS(X[i] - X[j], Y[i] - Y[j]) <= ll(R[i] - R[j]) * (R[i] - R[j])) {
				par[j] = i; rad[j] = R[i];
			}
	for (int i = 0; i < n; i++)
		if (rad[i] < Inf) neigh[par[i]].push_back(i);
	ld res = 0;
	for (int i = 0; i < n; i++)
		if (rad[i] >= Inf) {
			Traverse(i);
			res += dp[i][1][1];
		}
	res *= acos(-1.0l);
	cout << fixed << setprecision(16) << res << endl;
	return 0;
}