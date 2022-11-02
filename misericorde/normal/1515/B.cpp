#include <bits/stdc++.h>

int check(int x) {
	int u = std::sqrt(x);
//	printf("%d -> %d\n",u,x);
	if (u * u == x) return 1;
	return 0;
}

void solve() {
	int n;scanf("%d",&n);
	if (n % 2 == 1) { puts("NO"); return ; }
	int area = n / 2;
	if (check(area)) { puts("YES"); return ; }
	if (check(area * 2)) { puts("YES"); return ; }
	puts("NO");
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}