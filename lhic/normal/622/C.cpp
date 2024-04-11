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

int a[MAXN];
int n, m;
int nx[MAXN];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	nx[n - 1] = n;
	for (int i = n - 2; i >= 0; --i) {
		if (a[i] != a[i + 1])
			nx[i] = i + 1;
		else
			nx[i] = nx[i + 1];
	}
	for (int i = 0; i < m; ++i) {
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		--l;
		if (a[l] != x)
			printf("%d\n", l + 1);
		else {
			if (nx[l] < r)
				printf("%d\n", nx[l] + 1);
			else
				printf("-1\n");
		}
	}
	return 0;
}