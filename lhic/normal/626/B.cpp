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

int n;
string s;
int dp[201][201][201];
int cc[4];

int main() {
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'B')
			++cc[0];
		else if (s[i] == 'G')
			++cc[1];
		else
			++cc[2];
	}
	dp[cc[0]][cc[1]][cc[2]] = 1;
	for (int sum = n; sum >= 1; --sum) {
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= n; ++j) {
				if (i + j > sum || i + j + n < sum)
					continue;
				int k = sum - i - j;
				if (!dp[i][j][k])
					continue;
				if (i > 1)
					dp[i - 1][j][k] = 1;
				if (j > 1)
					dp[i][j - 1][k] = 1;
				if (k > 1)
					dp[i][j][k - 1] = 1;
				if (i && j)
					dp[i - 1][j - 1][k + 1] = 1;
				if (i && k)
					dp[i - 1][j + 1][k - 1] = 1;
				if (k && j)
					dp[i + 1][j - 1][k - 1] = 1;
			}
	}
	if (dp[1][0][0])
		cout << "B";
	if (dp[0][1][0])
		cout << "G";
	if (dp[0][0][1])
		cout << "R";

	return 0;
}