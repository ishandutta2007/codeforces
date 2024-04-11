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
typedef long double ld;

using namespace std;

const int MX = 60;
const int MAXN = 510000;

int n, q;
int p[MAXN];
ld dp[MAXN][MX];

void add(int a, int b) {
	p[a] = b;
	for (int i = 0; i < MX; ++i)
		dp[a][i] = 1;
	int now = a;
	int h = 0;
	ld lst = 1;
	while (h < MX && p[now] != -1) {
		int g = p[now];
		ld tmp = dp[g][h];
		if (g != b)
			dp[g][h] = (dp[g][h] / ((1 + lst) / 2)) * (1 + dp[now][h - 1]) / 2;
		else
			dp[g][h] = (dp[g][h] / 2);
		lst = tmp;
		++h;
		now = p[now];
	}
}


int main() {
	scanf("%d", &q);
	p[0] = -1;
	for (int i = 0; i < MX; ++i)
		dp[0][i] = 1;
	n = 1;
	for (int i = 0; i < q; ++i) {
		int t, v;
		scanf("%d%d", &t, &v);
		--v;
		if (t == 1) {
			add(n++, v);
		}
		else {
			ld ans = 0;
			for (int j = 0; j < MX; ++j)
				ans += 1 - dp[v][j];
			printf("%.7lf\n", (double)ans);
		}
	}
	return 0;
}