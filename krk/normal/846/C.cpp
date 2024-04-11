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

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 5005;
const int Maxd = 4;

int n;
int a[Maxn];
ll dp[Maxn][Maxd];
int wth[Maxn][Maxd];

int main()
{
	fill((ll*)dp, (ll*)dp + Maxn * Maxd, -Inf); dp[0][0] = 0;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		if (i < n) scanf("%d", &a[i]);
		for (int j = 0; j < Maxd; j++) {
			if (j + 1 < Maxd) {
				if (dp[i][j] > dp[i][j + 1]) {
					dp[i][j + 1] = dp[i][j]; wth[i][j + 1] = i;
				}
			}
			if (i < n)
				if (j % 2 == 0) {
					if (dp[i][j] + a[i] > dp[i + 1][j]) {
						dp[i + 1][j] = dp[i][j] + a[i];
						wth[i + 1][j] = wth[i][j];
					}
				}
				else {
					if (dp[i][j] - a[i] > dp[i + 1][j]) {
						dp[i + 1][j] = dp[i][j] - a[i];
						wth[i + 1][j] = wth[i][j];
					}
				}
		}
	}
	vector <int> seq;
	int r = n, c = Maxd - 1;
	while (c > 0) {
		seq.push_back(wth[r][c]);
		r = seq.back(); c--;
	}
	for (int i = int(seq.size()) - 1; i >= 0; i--)
		printf("%d%c", seq[i], i - 1 >= 0? ' ':'\n');
	return 0;
}