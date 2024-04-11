// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll read() {
    ll x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 200010;

ll n, p, i, j;
ll x[maxn], y[maxn];
ll w[maxn], s[maxn];
ll h, ans;

ll Max(ll a, ll b) {
	if (a > b) return a;
	else return b;
}

int main() {
//	freopen("D.in", "r", stdin);
//	freopen("D.out", "w", stdout);

	n = read(), h = read();
	for (int i = 1; i <= n; i++)
		x[i] = read(), y[i] = read();
	for (int i = 1; i < n; i++)
		w[i] = x[i + 1] - y[i];
	for (i = 1, j = 1; i <= n; i++) {
		h += w[i - 1];
//		printf("h += %d\n", w[i]);
		while (h > w[j] && j < n) {
			h -= w[j];
			j++;
		}
//		printf("%d %d %d %d %d\n", h, i, j, x[i], y[j],h);
		ans = Max(ans, y[j] - x[i] + h);
	}
	printf("%I64d\n", ans);

	return 0;
}