# include <bits/stdc++.h>
using namespace std;

char a[200010];
char b[200010];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s", a);
	scanf("%s", b);
	int k = find(a, a + n, '*') - a;
	if(k == n) {
		if(strcmp(a, b) == 0) {
			puts("YES");
		} else {
			puts("NO");
		}
	} else {
		int len = n - k - 1;
		bool v1 = (strncmp(a, b, k) == 0);
		bool v2 = (strncmp(a + n - len, b + m - len, len) == 0);
		if(v1 && v2 && (n - 1) <= m) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
}