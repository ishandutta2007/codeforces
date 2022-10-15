#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

#define N 1001115

int n;
int a[N];
LL s[N];

#define INF 0x7f7f7f7f7f7f7f7f

LL ans = INF;

void chk(LL p) {
	LL ret = 0;
	for (int i = 1; i <= n; i++) {
		auto x = (s[i] % p);
		ret += min(x, p - x);
	}
	ans = min(ret, ans);
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	LL x = s[n];
	for (int i = 2; (LL) i * i <= x; i++) {
		if (x % i == 0) {
			while (x % i == 0) x /= i;
			chk(i);
		}
	}
	if (x > 1) chk(x);
	cout << (ans == INF ? -1 : ans) << endl;
}