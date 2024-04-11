#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
void read(int &a) {scanf("%d", &a);}
void read(LL &a) {scanf("%lld", &a);}

const int N = 2e5 + 5;
int n, a[N], w[N], t[N];
pii b[N];
void work() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), b[i] = {a[i], -i};
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) {
		w[-b[i].second] = i;
	}
	for (int i = 1; i <= n; i++) t[i] = 0;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int x = n - w[i] + 1;
		for (int y = x; y; y -= y & -y) {
			ans += t[y];
		}
		for (int y = x; y <= n; y += y & -y) {
			t[y] ++;
		}
	}
	printf("%lld\n", ans);
}

int main() {
	int T;
	read(T);
	while (T--) work();
}