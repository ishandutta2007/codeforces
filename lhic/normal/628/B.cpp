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

char s[500000];

int main() {
	scanf(" %s", s + 1);
	s[0] = '0';
	int n = strlen(s);
	ll ans = 0;
	for (int i = 1; i < n; ++i) {
		int k = (s[i] - '0') + 10 * (s[i - 1] - '0');
		if (k % 4 == 0) {
			ans += max(0, i - 1);
		}
		if ((s[i] - '0') % 4 == 0)
			++ans;
	}
	cout << ans << "\n";
	return 0;
}