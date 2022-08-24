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
string s[1200];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	int ans = 6;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int df = 0;
			for (int k = 0; k < 6; ++k)
				if (s[i][k] != s[j][k])
					++df;
			ans = min(ans, (df - 1) / 2);
		}
	}
	cout << ans << "\n";
		
	return 0;
}