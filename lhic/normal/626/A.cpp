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

pair<int, int> add(pair<int, int> x, char c) {
	if (c == 'U')
		++x.first;
	else if (c == 'D')
		--x.first;
	else if (c == 'R')
		++x.second;
	else
		--x.second;
	return x;
}

int n;
string s;

int main() {
	cin >> n;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		pair<int, int> now = make_pair(0, 0);
		for (int j = i; j < n; ++j) {
			now = add(now, s[j]);
			if (now.first == 0 && now.second == 0)
				++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}