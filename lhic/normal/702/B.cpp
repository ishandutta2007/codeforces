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

map<int, int> mm;

int n;
int a[120000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n);
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		for (ll j = 2; j <= 2 * a[i]; j *= 2) {
			if (j <= a[i])
				continue;
			ans += mm[j - a[i]];
		}
		mm[a[i]]++;
	}
	cout << ans << "\n";

	return 0;
}