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

char s[200];
int n;

int main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	for (int i = n; i >= 1; i--)
		if (s[i] == '/') s[i] = '!';
		else break;
	if (s[1] == '!') putchar('/');
	for (int i = 1; i <= n; i++)
		if (s[i] == '!') break;
		else if (!(s[i] == '/' && s[i - 1] == '/'))
			putchar(s[i]);
	return 0;
}