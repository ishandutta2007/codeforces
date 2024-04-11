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

char readc() {
	char c = getchar();
	while (c != '.' && c != '*') c = getchar();
	return c;
}

const int maxn = 60;
int n, m;
char a[maxn][maxn];
int lx, ly, rx, ry;

int main() {
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = readc();
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] == '*') {
				if (!lx) {
					lx = rx = i;
					ly = ry = j;
				} else {
					lx = min(lx, i);
					rx = max(rx, i);
					ly = min(ly, j);
					ry = max(ry, j);
				}
			}
	for (int i = lx; i <= rx; i++) {
		for (int j = ly; j <= ry; j++)
			putchar(a[i][j]);
		putchar('\n');
	}
		
	return 0;
}