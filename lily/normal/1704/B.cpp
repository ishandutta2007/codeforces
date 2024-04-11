#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

const int N = 2e5 + 5;
int n, x;
int a[N];

int main() {
	int T;
	read(T);
	while (T--) {
		read(n); read(x);
		int lower = -1, upper = -1, ans = 0;
		for (int i = 1; i <= n; i++) {
			read(a[i]);
			if (lower == -1) lower = upper = a[i];
			lower = min(lower, a[i]);
			upper = max(upper, a[i]);
			if (upper - lower > 2 * x) {
				ans ++;
				lower = upper = a[i];
			}
		}
		printf("%d\n", ans);
	}

}