#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)

int a[105];
void work() {
	int n;
	read(n);
	printf("%d\n", n);
	for (int i = 1; i <= n; i++) a[i] = i;
	for (int T = 1; T <= n; T++) {
		for (int i = 1; i <= n; i++) printf("%d%c", a[i], i == n ? '\n' : ' ');
		swap(a[T], a[T + 1]);
	}
}

int main() {
	int T;
	read(T);
	while (T--) work();
}