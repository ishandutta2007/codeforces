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


LL n, k;

int main() {
	cin >> n >> k;
	if (LD(k + 1) * k > n * 4) return puts("-1"), 0;
	LL K = (k + 1) * k / 2; 
	LL Max = n / K, ans = -1;
	for (LL i = 1, j = (LL) sqrt(n); i <= j; i++) {
		if (!(n % i)) {
			if (i <= Max) ans = max(i, ans);
			if (n / i <= Max) ans = max(n / i, ans);
		}
	}
	if (~ans) {
		for (int i = 1; i < k; i++) {
			cout << ans * i << " ";
		}
		cout << n - ans * ((k - 1) * k / 2) << endl;
	}
	else cout << -1 << endl;
	return 0;
}