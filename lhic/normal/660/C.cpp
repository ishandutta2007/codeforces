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
const int MAXN = 400000;

int n, k;
int a[MAXN];
int pr[MAXN];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < n; ++i)
		pr[i + 1] = pr[i] + a[i];
	int l = 0;
	int r = n + 1;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		int fl = 0;
		for (int i = 0; i <= n - m; ++i) {
			if (pr[i + m] - pr[i] + k >= m) {
				fl = 1;
				break;
			}
		}
		if (fl)
			l = m;
		else
			r = m;
	}
	printf("%d\n", l);
	for (int i = 0; i <= n - l; ++i) {
		if (pr[i + l] - pr[i] + k >= l) {
			fill(a + i, a + i + l, 1);
			break;
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}