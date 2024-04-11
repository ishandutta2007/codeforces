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
const int MAXN = 1000010;
const int MX = 3000010;

ll sm[MX + 10];
int n;
int a[MAXN];
ll cc[MX];
ll ans[MX];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i), ++cc[a[i]];
	for (int i = MX - 1; i >= 0; --i)
		sm[i] = sm[i + 1] + cc[i];
	for (int i = 1; i < MX; ++i) {
		for (int j = 1; j < MX; ++j) {
			if (i == j)
				continue;
			if (i * j >= MX) {
				ll s = sm[j];
				if (i >= j)
					s -= cc[i];
				ans[MX - 1] += cc[i] * s;
				break;
			}
			ans[i * j] += cc[i] * cc[j];
		}
	}
	for (int i = 0; i < MX; ++i) {
		if (!cc[i])
			continue;
		ll g = (ll)i * i;
		g = min(g, (ll)MX - 1);
		ans[g] += cc[i] * (cc[i] - 1);
	}
	for (int j = MX - 2; j >= 0; --j)
		ans[j] += ans[j + 1];
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int p;
		scanf("%d", &p);
		printf("%lld\n", ans[p]);
	}
	return 0;
}