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

vector<string> vv;
string s;

int dp[100000][5];


int main() {
	cin >> s;
	int n = s.size();

	dp[n - 2][2] = 1;
	dp[n - 3][3] = 1;

	for (int i = n - 4; i >= 0; --i) {
		for (int j1 = 2; j1 <= 3; ++j1)
			for (int j2 = 2; j2 <= 3; ++j2) {
				if (i + j1 + j2 > n)
					continue;
				if (!dp[i + j1][j2])
					continue;
				if (s.substr(i, j1) == s.substr(i + j1, j2))
					continue;
				dp[i][j1] = 1;
			}
	}


	for (int i = 5; i < n; ++i) {
		if (dp[i][2]) {
			vv.push_back(s.substr(i, 2));
		}
		if (dp[i][3]) {
			vv.push_back(s.substr(i, 3));
		}
	}
	sort(vv.begin(), vv.end());
	vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
	cout << vv.size() << "\n";
	for (auto ss: vv)
		cout << ss << "\n";
	return 0;
}