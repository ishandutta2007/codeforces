/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
typedef long double LD;

#define MAXN 1000005

int k, n, len, maxn = 0, a[MAXN];
char s[MAXN];

void init() {
	n = 0;
	for (int i = 1, j; i <= len; i++) {
		j = i;
		while (i <= len && s[i] != ' ' && s[i] != '-') i++;
		a[++n] = i - j + (i <= len);
		maxn = max(a[n], maxn);
	}
}

bool check(int mid) {
	int now = mid, tot = 0;
	for (int i = 1; i <= n; i++) {
		now += a[i];
		if (now > mid) now = a[i], tot++;
	}
	return tot <= k;
}

int main() {
	scanf("%d\n", &k);
	cin.getline(s + 1, MAXN);
	len = int(strlen(s + 1));
	if (s[len] < ' ') len--;
	init();
	int l = maxn, r = len;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
	return 0;
}