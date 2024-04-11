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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

int cc[1000];
string s;

int main() {
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
		++cc[(int)s[i]];
	int ans = s.size();
	ans = min(ans, cc['B']);
	ans = min(ans, cc['u'] / 2);
	ans = min(ans, cc['l']);
	ans = min(ans, cc['b']);
	ans = min(ans, cc['a'] / 2);
	ans = min(ans, cc['s']);
	ans = min(ans, cc['r']);
	cout << ans << "\n";
	return 0;
}