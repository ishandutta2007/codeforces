#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)



int main() {
	int T;
	read(T);
	while (T--) {
		int n, m;
		read(n); read(m);
		int left = m - n;	
		if (left < 0) puts ("No");
		else if (n % 2) {
			puts ("Yes");
			for (int i = 1; i <= n; i++) {
				printf("%d ", i == n ? left + 1 : 1);
			}
			printf("\n");
		} else if (left % 2 == 0) {
			puts ("Yes");
			for (int i = 1; i <= n; i++) {
				printf("%d ", i >= n - 1 ? 1 + left / 2 : 1);
			}
			printf("\n");
		}
		else puts ("No");
	}
}