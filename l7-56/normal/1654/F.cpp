#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 1e6 + 10;
int n,m,rk[maxn],a[maxn],tmp[maxn];
char s[maxn];

int main() {
	scanf("%d%s", &n, s); m = 1 << n;
	for (int i = 0; i < m; ++i) a[i] = i;
	sort(a, a + m, [&](int x, int y) { return s[x] < s[y]; });
	for (int i = 1; i < m; ++i) rk[a[i]] = rk[a[i - 1]] + (s[a[i]] != s[a[i - 1]]);
	for (int w = 1; w < m; w <<= 1) {
		sort(a, a + m, [&](int x, int y) { return rk[x] == rk[y] ? rk[x ^ w] < rk[y ^ w] : rk[x] < rk[y]; });
		for (int i = 0; i < m; ++i) tmp[i] = rk[i];
		rk[a[0]] = 0;
		for (int i = 1; i < m; ++i)
			rk[a[i]] = rk[a[i - 1]] + (tmp[a[i]] != tmp[a[i - 1]] || tmp[a[i] ^ w] != tmp[a[i - 1] ^ w]);
	}
	for (int i = 0; i < m; ++i) putchar(s[a[0] ^ i]);
	printf("\n");
	return 0;
}