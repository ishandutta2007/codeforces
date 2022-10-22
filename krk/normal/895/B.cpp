#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, x, k;
int a[Maxn];
ll res;

int main()
{
	scanf("%d %d %d", &n, &x, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0, j; i < n; i = j) {
		j = i;
		while (j < n && a[i] == a[j]) j++;
		if (int(a[i] % x == 0) == k) res += ll(j - i) * (j - i);
	}
	for (int i = 0; i < n; i++) {
		int lef = 0, rig = i - 1;
		int res1 = i;
		while (lef <= rig) {
			int mid = lef + rig >> 1;
			if (a[i] / x - (a[mid] - 1) / x > k) lef = mid + 1;
			else { res1 = mid; rig = mid - 1; }
		}
		int res2 = -1;
		lef = 0, rig = i - 1;
		while (lef <= rig) {
			int mid = lef + rig >> 1;
			if (a[i] / x - (a[mid] - 1) / x < k || a[mid] == a[i]) rig = mid - 1;
			else { res2 = mid; lef = mid + 1; }
		}
		if (res1 <= res2) res += res2 - res1 + 1;
	}
	printf("%I64d\n", res);
	return 0;
}