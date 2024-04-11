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

int n, k, x;
ll arr[220000];
ll orl[220000];
ll orr[220000];

int main() {
	scanf("%d%d%d", &n, &k, &x);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &arr[i]);
	ll d = 1;
	for (int i = 0; i < k; ++i)
		d *= x;
	for (int i = 0; i < n; ++i) {
		orl[i + 1] = orl[i] | arr[i];
	}
	for (int i = n - 1; i > 0; --i) {
		orr[i - 1] = orr[i] | arr[i];
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, orl[i] | orr[i] | (arr[i] * d));
	}
	cout << ans << "\n";
	return 0;
}