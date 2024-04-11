#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n,m,a;

ll updiv(int x, int y) {
	if(x % y == 0) return x / y;
	return x / y + 1;
}

int main() {
	scanf("%d%d%d", &n, &m, &a);
	printf("%lld\n", updiv(n, a) * updiv(m, a));
	return 0;
}