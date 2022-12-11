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

int get(int a, int b, int c) {
	if (a + b > c) return 2;
	if (a + b == c) return 1;
	return 0;
}

int a[10], ans;

int main() {
	for (int i = 1; i <= 4; i++)
		a[i] = read();
	sort(a + 1, a + 5);
	ans = max(ans, get(a[1], a[2], a[3]));
	ans = max(ans, get(a[1], a[2], a[4]));
	ans = max(ans, get(a[1], a[3], a[4]));
	ans = max(ans, get(a[2], a[3], a[4]));
	if (ans == 2) puts("TRIANGLE");
	else if (ans == 1) puts("SEGMENT");
	else puts("IMPOSSIBLE");
	return 0;
}