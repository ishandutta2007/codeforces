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
const int MAXN = 510000;

int n, k;
int c[MAXN];
ll sum = 0;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", c + i), sum += c[i];
	k = min((ll)k, sum);
	sort(c, c + n);
	int tmp = k;
	for (int i = n - 1; i >= 0; --i) {
		ll pr = 0;
		if (i != 0)
			pr = c[i - 1];
		ll df = c[i] - pr;
		ll now = n - i;
		if (df * now < k) {
			k -= df * now;
		}
		else {
			if (df * now == k) {
				for (int j = i; j < n; ++j)
					c[j] = pr;
			}
			else {
				ll lv = k / now;
				ll gg = k - lv * now;
				lv = c[i] - lv;
				for (int j = i; j < n; ++j)
					c[j] = lv;
				for (int j = i; j < i + gg; ++j)
					--c[j];
			}
			break;
		}
	}
	k = tmp;
	for (int i = 0; i < n; ++i) {
		ll pr = 1e9 + 100;
		if (i != n - 1)
			pr = c[i + 1];
		ll df = pr - c[i];
		ll now = i + 1;
		if (df * now < k) {
			k -= df * now;
		}
		else {
			if (df * now == k) {
				for (int j = 0; j <= i; ++j)
					c[j] = pr;
			}
			else {
				ll lv = k / now;
				ll gg = k - lv * now;
				lv = c[i] + lv;
				for (int j = 0; j <= i; ++j)
					c[j] = lv;
				for (int j = i - gg + 1; j <= i; ++j)
					++c[j];
			}
			break;
		}
	}
	cout << c[n - 1] - c[0] << "\n";
	return 0;
}