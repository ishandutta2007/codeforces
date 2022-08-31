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
typedef double ld;

using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		int mn = 2e9;
		for (int j = 0; j < m; ++j) {
			int a;
			cin >> a;
			mn = min(mn, a);
		}
		mx = max(mx, mn);
	}
	cout << mx << "\n";
	return 0;
}