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

int n;
ll k;
ll a[120000];
ll pr[120000];
map<ll, int> mm;
ll ans = 0;
const ll mx = 1e16;

int main() {
	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i);
	for (int i = 0; i < n; ++i)
		pr[i + 1] = pr[i] + a[i];
	++mm[0];
	for (int i = 1; i <= n; ++i) {
		ll now = 1;
		if (k == 1) {
			ans += mm[pr[i] - 1];
		}
		else  if (k == -1) {
			ans += mm[pr[i] - 1];
			ans += mm[pr[i] + 1];
		}
		else {
			while (abs(now) < mx) {
				ans += mm[pr[i] - now];
				now *= k;
			}
		}
		mm[pr[i]]++;
	}
	cout << ans << "\n";
	return 0;
}