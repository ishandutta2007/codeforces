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

int n;
int a[MAXN];
ld bst;
int bstst;
int bstl;

void solve1r() {
	ll sum = a[0];
	int now = 0;
	for (int i = 0; i < n; ++i) {
		while (now > 0 && (a[now - 1] + a[i + now]) / 2.0 < (ld)sum / (now * 2 + 1))
			sum -= a[now - 1] + a[i + now], --now;
		while (now < i && i + now + 1 < n && (a[now] + a[i + now + 1]) / 2.0 > (ld)sum / (now * 2 + 1))
			++now, sum += a[now - 1] + a[i + now];
		if ((ld)sum / (2 * now + 1) - a[i] > bst)
			bst = (ld)sum / (2 * now + 1) - a[i], bstl = now * 2 + 1, bstst = i;
		sum -= a[i];
		if (now == 0) {
			sum += a[i + 1];
		}
		else {
			--now;
			sum -= a[now];
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n);
	reverse(a, a + n);
	bst = -1;
	bstl = 0;
	bstst = 0;

	solve1r();

	printf("%d\n", bstl);
	if (bstl % 2 == 0) {
		int g = (bstl - 2) / 2;
		for (int i = 0; i < g; ++i)
			printf("%d ", a[i]);
		printf("%d ", a[bstst]);
		printf("%d ", a[bstst + 1]);
		for (int i = bstst + 2; i < bstst + 2 + g; ++i)
			printf("%d ", a[i]);
		printf("\n");
	}
	else {
		int g = (bstl - 1) / 2;
		for (int i = 0; i < g; ++i)
			printf("%d ", a[i]);
		printf("%d ", a[bstst]);
		for (int i = bstst + 1; i < bstst + 1 + g; ++i)
			printf("%d ", a[i]);
		printf("\n");
	}
	return 0;
}