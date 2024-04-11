#include <bits/stdc++.h>
using namespace std;

int t;
int a, b, n;

int main () {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &a, &b, &n);
		int cur = 0;
		while (a <= n && b <= n) {
			if (a > b) swap(a, b);
			a += b;
			cur++;
		}
		printf("%d\n", cur);
	}
	return 0;
}