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
const int MAXN = 500000;

int n, k;
int a[MAXN];
ll b[MAXN];
int ans;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= n; ++i)
		scanf("%d", a + i), b[i] = a[i];
	int p = 0;
	int mn = 500000;
	int mx = 0;
	for (int i = 0; i <= n || p; ++i) {
		b[i] += p;
		p = b[i] / 2;
		b[i] %= 2;
		if (b[i])
			mn = min(mn, i), mx = max(mx, i);
	}
	ll now = 0;
	for (int i = mx; i >= mn; --i) {
		now = now * 2 + b[i];
		if (abs(now) > 4ll * k) {
			cout << 0 << "\n";
			return 0;
		}
	}
	for (int i = mn; i >= 0; --i) {
		if (abs(a[i] - now) <= k && i <= n) {
			if (a[i] != now || i != n)
				++ans;
		}
		now *= 2;
		if (abs(now) > 4ll * k)
			break;
	}
	cout << ans << "\n";
	return 0;
}