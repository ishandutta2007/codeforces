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

const ll MOD = 1000000007;
int p, k;
int was[1200000];
int cnt;

int main() {
	scanf("%d%d", &p, &k);
	if (k == 0) {
		ll ans = 1;
		for (int i = 0; i < p - 1; ++i)
			ans = (ans * p) % MOD;
		cout << ans << "\n";
		return 0;
	}
	if (k != 1)
		was[0] = 1;
	for (int i = 0; i < p; ++i) {
		if (was[i])
			continue;
		++cnt;
		ll now = i;
		while (!was[now]) {
			was[now] = 1;
			now = (now * k) % p;
		}
	}
	ll ans = 1;
	for (int i = 0; i < cnt; ++i)
		ans = (ans * p) % MOD;
	cout << ans << "\n";
	return 0;
}