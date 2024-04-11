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

const int MX = (1 << 10);
int a[MX];
int b[MX];
int n, k, x;

int main() {
	scanf("%d%d%d", &n, &k, &x);
	for (int i = 0; i < n; ++i) {
		int bb;
		scanf("%d", &bb);
		++a[bb];
	}
	for (int i = 0; i < k; ++i) {
		memset(b, 0, sizeof(b));
		int now = 0;
		for (int j = 0; j < MX; ++j) {
			if (now & 1) {
				b[j ^ x] += (a[j] >> 1);
				b[j] += (a[j] - (a[j] >> 1));
			}
			else {
				b[j] += (a[j] >> 1);
				b[j ^ x] += (a[j] - (a[j] >> 1));
			}
			now += a[j];
		}
		memcpy(a, b, sizeof(b));
	}
	int mn = MX;
	int mx = 0;
	for (int i = 0; i < MX; ++i)
		if (a[i])
			mn = min(mn, i), mx = max(mx, i);
	cout << mx << " " << mn << "\n";
	return 0;
}