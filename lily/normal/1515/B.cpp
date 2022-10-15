#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		scanf("%d", &n);
		if (n <= 1) {
			puts("NO");
			continue;
		}
		bool flag = 0;
		flag |= (n % 4 == 0 && int(sqrt(n / 4)) * int(sqrt(n / 4)) == n / 4);
		flag |= (n % 2 == 0 && int(sqrt(n / 2)) * int(sqrt(n / 2)) == n / 2);
		flag &= (n % 2 == 0);
		puts(flag ? "YES" : "NO");
	}
}