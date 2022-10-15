#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

#define N 404004

int n, I, m;
int a[N];
map <int, int> G;
int b[N];
int work() {
	m = 1 << I;
	for (int i = 1; i <= n; i++) {
		G[a[i]]++;
	}
	int k = 0;
	for (auto &v : G) {
		k++;
		b[k] = b[k - 1] + v.second;
	}
	if (m > k) return 0;
	int ans = 0x3f3f3f3f;
	for (int i = m; i <= k; i++) {
		ans = min(ans, n - (b[i] - b[i - m]));
	}
	return ans;
}


int main() {
	read(n); read(I);
	for (int i = 1; i <= n; i++) read(a[i]);
	I *= 8;
	I /= n;
	if (I > 20) puts("0");
	else {
		cout << work() << endl;;
	}
}