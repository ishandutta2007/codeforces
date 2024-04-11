/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;
#define MAXN 100005
int n, ans = 1;
int cnt[MAXN];
bool notprime[MAXN];

void init() {
	for (int i = 2; i <= 100000; i++) {
		if (!notprime[i]) {
			int ret = 0;
			for (int j = i; j <= 100000; j += i) {
				ret += cnt[j]; notprime[j] = 1;
			}
			ans = max(ans, ret);
		}
	}
}


int main() {
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i++) scanf("%d", &x), cnt[x]++;
	init();
	printf("%d\n", ans);
	return 0;
}