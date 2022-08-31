#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef double ld;

using namespace std;
const int MAXN = 300000;

int n;
ll x, y;

int dp[MAXN][2];
vector<int> eds[MAXN];
int was[MAXN];

void dfs(int v) {
	was[v] = 1;
	int a = 0, b = 0, c = 0;
	for (int u: eds[v]) {
		if (was[u])
			continue;
		dfs(u);
		int x = max(dp[u][0], dp[u][1]);
		c = max(c + x, b + 1 + dp[u][0]);
		b = max(b + x, a + 1 + dp[u][0]);
		a += x;
	}
	dp[v][0] = max(a, b);
	dp[v][1] = c;
}


int main() {
	scanf("%d%lld%lld", &n, &x, &y);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	if (y <= x){
		for (int i = 0; i < n; ++i)
			if ((int)eds[i].size() == n - 1) {
				cout << y * (n - 2) + x << "\n";
				return 0;
			}
		cout << y * (n - 1) << "\n";
		return 0;
	}

	dfs(0);

	int xx = max(dp[0][0], dp[0][1]);
	cout << xx * x + (n - 1 - xx) * y << "\n";

	return 0;
}