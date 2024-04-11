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
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n, k;
vector <ii> neigh[Maxn];
int dp[Maxn][2];

void Solve(int v, int p)
{
	vector <ii> vals;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.first == p) continue;
		Solve(u.first, v);
		vals.push_back(ii(dp[u.first][0] + u.second, dp[u.first][1] + u.second));
	}
	sort(vals.rbegin(), vals.rend());
	for (int i = 0; i < vals.size() && i < k - 1; i++)
		dp[v][0] += vals[i].first;
	for (int i = 0; i < vals.size(); i++)
		if (i < k - 1) {
			int cand = dp[v][0] - vals[i].first + vals[i].second;
			if (k - 1 < vals.size()) cand += vals[k - 1].first;
			dp[v][1] = max(dp[v][1], cand);
		} else dp[v][1] = max(dp[v][1], dp[v][0] + vals[i].second);
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		neigh[a].push_back(ii(b, c));
		neigh[b].push_back(ii(a, c));
	}
	Solve(0, -1);
	printf("%d\n", dp[0][1]);
	return 0;
}