// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 110;

int n, min, a[maxn], b[maxn];

int main() {
	
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++)
		b[i] = abs(a[i] - a[i % n + 1]);
	for (int i = 1; i <= n; i++)
		if (b[i] < b[min] || !min)
			min = i;
	printf("%d %d\n", min, min % n + 1);
	
	return 0;
}