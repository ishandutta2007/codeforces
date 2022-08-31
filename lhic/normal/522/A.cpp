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
#include <unordered_map>


typedef long long ll;
typedef long double ld;

using namespace std;

int n;

unordered_map<string, int> mm;
int ans;

int main() {
	cin >> n;
	mm["polycarp"] = 1;
	ans = 1;
	for (int i = 0; i < n; ++i) {
		string s1, s2, s;
		cin >> s1 >> s >> s2;
		for (int j = 0; j < (int)s1.size(); ++j)
			if (s1[j] >= 'A' && s1[j] <= 'Z')
				s1[j] = (char)('a' + (s1[j] - 'A'));
		for (int j = 0; j < (int)s2.size(); ++j)
			if (s2[j] >= 'A' && s2[j] <= 'Z')
				s2[j] = (char)('a' + (s2[j] - 'A'));
		mm[s1] = mm[s2] + 1;
		ans = max(ans, mm[s1]);
	}
	cout << ans;
	return 0;
}