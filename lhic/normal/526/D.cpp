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

const int MAXN = 1200000;

int n, k;

char s[MAXN];
int z[MAXN];
int ans[MAXN];

int main() {
	scanf("%d%d", &n, &k);
	scanf(" %s", s);
	z[0] = 0;
	int l = 0;
	int r = 0;
	for (int i = 1; i < n; ++i) {
		if (i < r)
			z[i] = min(r - i, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] > r)
			r = i + z[i], l = i;
	}

	r = 0;

	for (int i = 0; i < n; ++i) {
		if (r > i)
			ans[i] = 1;
		if ((i + 1) % k == 0) {
			int x = (i + 1) / k;
			int fl = 0;
			for (int j = x; j < i + 1; j += x) {
				if (z[j] < x) {
					fl = 1;
					break;
				}
			}
			if (!fl) {
				ans[i] = 1;
				if (i != n - 1)
					r = max(r, i + 1 + min(x, z[i + 1]));
			}
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d", ans[i]);

	return 0;
}