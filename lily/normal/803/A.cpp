/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
typedef long double LD;

int n, k;
int G[105][105];

int main() {
	cin >> n >> k;
	if (n * n < k) cout << -1 << endl;
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int now;
				if (i == j) now = 1;
				else now = 2 - G[i][j] - G[j][i];
				if (k >= now) k -= now, G[i][j] = G[j][i] = 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << G[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}