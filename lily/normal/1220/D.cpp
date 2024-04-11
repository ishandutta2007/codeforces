#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)


#define N 202022

int n;
LL a[N];

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
	}

	int mi = n, flag = -1;
	for (int j = 0; j < 61; j++) {
		int tmp = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] & ((1ll << j ) - 1) || (a[i] >> j) % 2 == 0) tmp++;
		}
		if (tmp < mi) {
			mi = tmp;
			flag = j;
		}
	}
	printf("%d\n", mi);
	for (int i = 1; i <= n; i++) {
		if (a[i] & ((1ll << flag) - 1) || (a[i] >> flag) % 2 == 0) printf("%lld ", a[i]);
	}
}