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

const int MAXN = 300000;

int n, k, a, b, q;
int arr1[MAXN];
int arr2[MAXN];
int f1[MAXN];
int f2[MAXN];

void add1(int x, int y) {
	y = min(y, b - arr1[x]);
	arr1[x] += y;
	for (; x < n; x |= (x + 1))
		f1[x] += y;
}

void add2(int x, int y) {
	x = n - 1 - x;
	y = min(y, a - arr2[x]);
	arr2[x] += y;
	for (; x < n; x |= (x + 1))
		f2[x] += y;
}

int get1(int l) {
	int ans = 0;
	for (; l >= 0; l &= (l + 1), --l)
		ans += f1[l];
	return ans;
}

int get2(int l) {
	l = n - 1 - l;
	int ans = 0;
	for (; l >= 0; l &= (l + 1), --l)
		ans += f2[l];
	return ans;
}



int main() {
	scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
	for (int i = 0; i < q; ++i) {
		int x, y;
		int t;
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d", &x, &y);
			--x;
			add1(x, y);
			add2(x, y);
		}
		else {
			int p;
			scanf("%d", &p);
			--p;
			int ans = 0;
			ans += get1(p - 1);
			ans += get2(p + k);
			printf("%d\n", ans);
		}
	}
	return 0;
}