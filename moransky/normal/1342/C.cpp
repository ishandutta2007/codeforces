#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

int ans[40005];

int a, b, q, c;

LL work(LL x) {
	LL s = x / c;
	return (LL)s * ans[c - 1] + ans[x % c]; 
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &a, &b, &q);
		c = a * b;
		for (int i = 0; i < c; i++){
			ans[i] = 0;
			if ((i % a) % b != (i % b) % a) ans[i]++; 
		}
		for (int i = 1; i < c; i++) ans[i] += ans[i - 1];
		while (q--) {
			LL l, r; scanf("%lld%lld", &l, &r);
			printf("%lld ", work(r) - work(l - 1));
		}
		puts("");
	}
	return 0;
}