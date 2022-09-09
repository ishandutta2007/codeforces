#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 10;

char a[N], b[N];
int n, m, have = 0;

int main() {
	cin >> n >> m;
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	if(n > m + 1) {
		puts("NO");
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] == '*') {
			have = 1;
			break;
		}
		if(a[i] != b[i]) {
			puts("NO");
			return 0;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(a[n - i + 1] == '*') {
			have = 1;
			break;
		}
		if(a[n - i + 1] != b[m - i + 1]) {
			puts("NO");
			return 0;
		}
	}
	if(!have && n != m) puts("NO");
	else puts("YES");
	return 0;
}