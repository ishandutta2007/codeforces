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

const int MX = 10011;
ll cc[MX];
int cb[MX * 2];
int n, k;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		++cc[x];
	}
	for (int i = 0; i < MX * 2; ++i)
		cb[i] = (__builtin_popcount(i) == k ? 1 : 0);
	ll ans = 0;
	if (k == 0) {
		for (int i = 0; i < MX; ++i)
			ans += (cc[i] * (cc[i] - 1)) / 2;
	}
	else {
		for (int i = 0; i < MX; ++i) {
			for (int j = i + 1; j < MX; ++j)
				if (cb[i ^ j])
					ans += cc[i] * cc[j];
		}
	}
	cout << ans << "\n";
	return 0;
}