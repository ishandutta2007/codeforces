#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef double db;
using namespace std;

int T,n,m;

int calc(int n, int m) {
	if(n > m) swap(n, m);
	if(n == 0) return 0;
	if(m == 2) return n;
	if(n == 1 && m % 3 == 1)
		return (m - 4) / 3 + 2;
	return m / 3 * n + calc(n, m % 3);
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		printf("%d\n", calc(n, m));
	}
	return 0;
}