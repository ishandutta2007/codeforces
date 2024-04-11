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

string s[100];


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	vector<char> ans = {'a', 'c', 'e', 'f'};
	int cnt = 0;
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < m - 1; ++j) {
			vector<char> a;
			a.push_back(s[i][j]);
			a.push_back(s[i + 1][j]);
			a.push_back(s[i][j + 1]);
			a.push_back(s[i + 1][j + 1]);
			sort(a.begin(), a.end());
			if (a == ans)
				++cnt;
		}
	cout << cnt;
	return 0;
}