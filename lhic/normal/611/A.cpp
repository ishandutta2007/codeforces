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


int main() {
	int x;
	string s1, s2;
	cin >> x >> s1 >> s2;
	if (s2 == "week") {
		int ans = 0;
		--x;
		for (int i = 0, now = 4; i < 366; ++i, now = (now + 1) % 7) {
			if (now == x)
				++ans;
		}
		cout << ans << "\n";
	}
	else {
		if (x <= 29) {
			cout << 12 << "\n";
		}
		else if (x == 30) {
			cout << 11 << "\n";
		}
		else {
			cout << 7 << "\n";
		}
	}
	return 0;
}