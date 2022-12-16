#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn],n,T;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		for(int i = 2; i <= n / 2 + 1; ++i) printf("%d %d\n", a[i], a[1]);
	}
	return 0;
}