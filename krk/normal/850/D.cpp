#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;
const int Maxm = 6005;
const int Maxk = 33;

int k;
int a[Maxk];
bool dp[Maxn][Maxm][Maxk];
int par[Maxn][Maxm][Maxk], oldz[Maxn][Maxm][Maxk];
char B[Maxn][Maxn];

int main()
{
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
		scanf("%d", &a[i]);
	sort(a, a + k);
	dp[0][0][0] = true; par[0][0][0] = -1;
	for (int i = 0; i < Maxn; i++)
		for (int j = 0; j < Maxm; j++)
			for (int z = 0; z <= k; z++) if (dp[i][j][z]) {
				if (i + 1 < Maxn && z > 0 && j + a[z - 1] >= (i + 1) * i / 2) {
					dp[i + 1][j + a[z - 1]][z] = true; par[i + 1][j + a[z - 1]][z] = z - 1;
					oldz[i + 1][j + a[z - 1]][z] = z;
				}
				if (i + 1 < Maxn && z < k && j + a[z] >= (i + 1) * i / 2) {
					dp[i + 1][j + a[z]][z + 1] = true; par[i + 1][j + a[z]][z + 1] = z;
					oldz[i + 1][j + a[z]][z + 1] = z;
				}
			}
	int n = 1;
	while (n < Maxn && !dp[n][n * (n - 1) / 2][k]) n++;
	if (n >= Maxn) { printf("=(\n"); return 0; }
	int p1 = n, p2 = n * (n - 1) / 2, p3 = k;
	vector <ii> V;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			B[i][j] = '0';
		B[i][n] = '\0';
	}
	for (int i = 0; i < n; i++) {
		int tk = par[p1][p2][p3];
		V.push_back(ii(a[tk], i));
		p3 = oldz[p1][p2][p3];
		p1--; p2 -= a[tk];
	}
	while (!V.empty()) {
		sort(V.begin(), V.end());
		ii v = V.back(); V.pop_back();
		for (int i = 0; i < v.first; i++)
			B[v.second][V[i].second] = '1';
		for (int i = v.first; i < V.size(); i++) {
			B[V[i].second][v.second] = '1'; V[i].first--;
		}
	}
	printf("%d\n", n);
	for (int i = 0; i < n; i++)
		printf("%s\n", B[i]);
	return 0;
}