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
const int MAXN = 300000;
int n;
int p[MAXN];
ll a[MAXN];

vector<int> eds[MAXN];

ll dp0[MAXN];
ll dp1[MAXN];


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i] >> a[i];
		if (p[i] != -1)
			--p[i];
		if (p[i] != -1)
			eds[p[i]].push_back(i);
	}
	for (int i = n - 1; i >= 0; --i) {
		ll x0 = 0;
		ll x1 = -1000000000ll * 1000000ll;
		for (int j = 0; j < (int)eds[i].size(); ++j) {
			int u = eds[i][j];
			ll x0t = max(x0 + dp0[u], x1 + dp1[u]);
			ll x1t = max(x1 + dp0[u], x0 + dp1[u]);
			x0 = x0t;
			x1 = x1t;
		}
		dp0[i] = x0;
		dp1[i] = max(x1, x0 + a[i]);
	}

	cout << max(dp0[0], dp1[0]);
	return 0;
}