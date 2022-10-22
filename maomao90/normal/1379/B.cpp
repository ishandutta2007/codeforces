#include <bits/stdc++.h>
using namespace std;
 
int t;
int l, r;
long long m;
 
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%lld", &l, &r, &m);
		for (int i = l; i <= r; i++) {
			int rem = m % i;
			if (rem <= r - l && m >= i) {
				printf("%d %d %d\n", i, l + rem, l);
				break;
			}
			rem = i - rem;
			if (rem <= r - l) {
				printf("%d %d %d\n", i, l, l + rem);
				break;
			}
		}
	}
	return 0;
}