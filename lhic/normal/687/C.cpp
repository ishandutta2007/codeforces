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

const int MAXN = 510;

int n, k;
int dp[MAXN][MAXN];
int c[MAXN];


int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", c + i);
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = k; j >= 0; --j)
			for (int j1 = k; j1 >= 0; --j1)
				if (dp[j][j1]) {
					if (j + c[i] <= k)
						dp[j + c[i]][j1] = 1;
					if (j1 + c[i] <= k)
						dp[j][j1 + c[i]] = 1;
				}
	}
	vector<int> ans;
	for (int i = 0; i <= k; ++i)
		if (dp[i][k - i])
			ans.push_back(i);
	cout << ans.size() << "\n";
	for (int i: ans)
		cout << i << " ";
	cout << "\n";
	return 0;
}