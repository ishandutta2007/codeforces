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


int dp[2000000];
int n, m;
string s[30];
int cc[30][30];
vector<pair<int, int> > go;
int dd[30];
int mx[30];
int sm[30];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> cc[i][j];
	for (int i = 0; i < n; ++i) {
		int fl = 0;
		for (int j = 0; j < m; ++j) {
			int fl2 = 0;
			for (int i1 = 0; i1 < n; ++i1)
				if (i1 != i && s[i1][j] == s[i][j]) {
					fl2 = 1;
					break;
				}
			if (!fl2) {
				fl = 1;
				break;
			}
		}
		if (fl)
			go.push_back(make_pair(1 << i, 0));
		else {
			int mn = cc[i][0];
			for (int j = 0; j < m; ++j)
				mn = min(mn, cc[i][j]);
			go.push_back(make_pair(1 << i, mn));
		}
	}
	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < 26; ++i)
			dd[i] = 0, mx[i] = 0, sm[i] = 0;
		for (int i = 0; i < n; ++i) {
			dd[s[i][j] - 'a'] |= 1 << i;
			mx[s[i][j] - 'a'] = max(mx[s[i][j] - 'a'], cc[i][j]);
			sm[s[i][j] - 'a'] += cc[i][j];
		}
		for (int i = 0; i < 26; ++i) {
			if (__builtin_popcount(dd[i]) > 1)
				go.push_back(make_pair(dd[i], sm[i] - mx[i]));
		}
	}

	for (int i = 0; i < (1 << n); ++i)
		dp[i] = 30000000;
	dp[0] = 0;
	for (int i = 0; i < (1 << n) - 1; ++i) {
		for (int j = 0; j < (int)go.size(); ++j)
			dp[i | go[j].first] = min(dp[i | go[j].first], dp[i] + go[j].second);
	}

	cout << dp[(1 << n) - 1];


	return 0;
}