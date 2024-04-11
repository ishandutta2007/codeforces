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

int read1d() {
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	return c - '0';
}

const int maxn = 110;
int n, m, a[maxn][maxn];

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = read1d();
	for (int i = 1; i <= n; i++)
		for (int j = 2; j <= m; j++)
			if (a[i][j - 1] != a[i][j]) {
				puts("NO");
				return 0;
			}
	for (int i = 2; i <= n; i++)
		if (a[i - 1][1] == a[i][1]) {
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}