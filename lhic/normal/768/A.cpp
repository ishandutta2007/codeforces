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

vector<int> vv;
int mn = 1e9 + 100;
int mx = 0;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		mn = min(mn, x);
		mx = max(mx, x);
		vv.push_back(x);
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (vv[i] > mn && vv[i] < mx)
			++cnt;
	}
	cout << cnt << "\n";
	return 0;
}