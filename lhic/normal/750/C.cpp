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

int n;
const int INF = 1e9;

int main() {
	scanf("%d", &n);
	int cur = 0;
	int mn = -INF;
	int mx = INF;
	for (int i = 0; i < n; ++i) {
		int c, d;
		scanf("%d%d", &c, &d);
		if (d == 1)
			mn = max(mn, 1900 - cur);
		else
			mx = min(mx, 1899 - cur);
		cur += c;
	}
	if (mn > mx) {
		cout << "Impossible\n";
	}
	else {
		if (mx == INF)
			cout << "Infinity\n";
		else
			cout << mx + cur << "\n";
	}
	return 0;
}