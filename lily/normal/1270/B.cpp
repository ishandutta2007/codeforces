
#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;
typedef long long LL;

int n, a[2123123];

void work() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 2; i <= n; i++) {
		if (abs(a[i] - a[i - 1]) > 1) {
			puts("YES");
			printf("%d %d\n", i - 1, i);
			return;
		}
	}
	puts("NO");
}

int main() {
	int T;
	cin >> T;
	while (T--) work();


}