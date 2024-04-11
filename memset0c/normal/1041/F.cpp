// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 100010;

int n, m, y1, y2, ans;
int a[maxn] , b[maxn];

map < int, int > p;

int main() {

	n = read(), y1 = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	
	m = read(), y2 = read();
	for (int i = 1; i <= m; i++)
		b[i] = read();
		
	if (n == 1 && m == 1 && a[1] == b[1]) {
		printf("%d\n", 2);
		return 0;
	}
	
	for (int k = 2; k <= 1e9; k <<= 1) {
		for (int i = 1; i <= n; i++) {
			p[a[i] % k]++;
			ans = max(ans, p[a[i] % k]);
		}
		for (int i = 1; i <= m; i++) {
			p[(b[i] + (k >> 1)) % k]++;
			ans = max(ans, p[(b[i] + (k >> 1)) % k]);
		}
		p.clear();
	}
	printf("%d\n", ans);

	return 0;
}