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

int n, m;
string s[1000];
int dp1[1000][1000];
int dp2[1000][1000];


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			dp1[i + 1][j + 1] = dp1[i][j + 1] + dp1[i + 1][j] - dp1[i][j];
			dp2[i + 1][j + 1] = dp2[i][j + 1] + dp2[i + 1][j] - dp2[i][j];
			if (i > 0 && s[i][j] == '.' && s[i - 1][j] == '.')
				++dp1[i + 1][j + 1];
			if (j > 0 && s[i][j] == '.' && s[i][j - 1] == '.')
				++dp2[i + 1][j + 1];
		}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		--x1, --x2;

		--y1, --y2;
		int ans = dp1[x2 + 1][y2 + 1] - dp1[x2 + 1][y1] - dp1[x1 + 1][y2 + 1] + dp1[x1 + 1][y1];
		ans += dp2[x2 + 1][y2 + 1] - dp2[x2 + 1][y1 + 1] - dp2[x1][y2 + 1] + dp2[x1][y1 + 1];
		printf("%d\n", ans);
	}
	return 0;
}