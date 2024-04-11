#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

int n;
int a[123123], b[123123];
int ra[123123], rb[123123];

int t[123123];
void upd(int x) {
	x = n - x + 1;
	for ( ; x <= n; x += x & -x) t[x]++;
}
int qry(int x) {
	x = n - x + 1;
	int ret = 0;
	for ( ; x; x -= x & -x) ret += t[x];
	return ret;
}


int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), ra[a[i]] = i;
	for (int i = 1; i <= n; i++) read(b[i]), rb[b[i]] = i;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (qry(rb[a[i]])) ans++;
		upd(rb[a[i]]);
	}
	printf("%d\n", ans);
}