#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a)

const int N = 5055;

int n;
int a[N], b[N];

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) read(b[i]);
	LL ans = 0;
	for (int i = 1; i <= n; i++) ans += (LL)a[i] * b[i];
	LL ret = ans;
	// reverse : c
	for (int i = 1; i <= n; i++) {
		LL cur = ans;
		for (int j = i - 1, k = i + 1; j >= 1 && k <= n; j--, k++) {
			cur -= (LL)a[j] * b[j] + (LL)a[k] * b[k];
			cur += (LL)a[j] * b[k] + (LL)a[k] * b[j];
			ret = max(ret, cur);
		}
	}
	for (int i = 1; i <= n; i++) {
		LL cur = ans;
		for (int j = i, k = i + 1; j >= 1 && k <= n; j--, k++) {
			cur -= (LL)a[j] * b[j] + (LL)a[k] * b[k];
			cur += (LL)a[j] * b[k] + (LL)a[k] * b[j];
			ret = max(ret, cur);
		}
	}
	printf("%lld\n", ret);
}