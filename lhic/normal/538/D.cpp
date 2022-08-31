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
vector<pair<int, int> > vv[3];
char arr[100][100];

int dp[300][300];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		scanf(" %s", arr[i]);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (arr[i][j] == 'o')
				vv[0].push_back(make_pair(i, j));
			else if (arr[i][j] == 'x')
				vv[1].push_back(make_pair(i, j));
			else
				vv[2].push_back(make_pair(i, j));
		}
	}
	for (int i = 0; i < (int)vv[2].size(); ++i)
		for (int j = 0; j < (int)vv[0].size(); ++j) {
			int dx = vv[2][i].first - vv[0][j].first, dy = vv[2][i].second - vv[0][j].second;
			dp[dx + n][dy + n] = 1;
		}
	
	for (int i = 0; i < (int)vv[1].size(); ++i) {
		int fl = 0;
		for (int j = 0; j < (int)vv[0].size(); ++j) {
			int dx = vv[1][i].first - vv[0][j].first, dy = vv[1][i].second - vv[0][j].second;
			if (dp[dx + n][dy + n] != 1)
				fl = 1;
		}
		if (!fl) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES\n";
	for (int i = -n + 1; i < n; ++i) {
		for (int j = -n + 1; j < n; ++j) {
			if (i == 0 && j == 0) {
				cout << "o";
			}
			else if (dp[i + n][j + n])
				cout << ".";
			else
				cout << "x";
		}
		cout << "\n";
	}
	return 0;
}