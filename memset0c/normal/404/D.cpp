// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 1000010, p = 1e9 + 7;

int n, flag, f[maxn][2][2];
char a[maxn];

bool check() {
	for (int i = 1; i <= n; i++)
		switch (a[i]) {
			case '1':
				if ((a[i - 1] == '*' ? 1 : 0) + (a[i + 1] == '*' ? 1 : 0) != 1)
					return false;
				break;
			case '2':
				if ((a[i - 1] == '*' ? 1 : 0) + (a[i + 1] == '*' ? 1 : 0) != 2)
					return false;
				break;
			case '0':
				if ((a[i - 1] == '*' ? 1 : 0) + (a[i + 1] == '*' ? 1 : 0) != 0)
					return false;
				break;
		}
	return true;
}

int main() {
//	freopen("mine.in", "r", stdin);
//	freopen("mine.out", "w", stdout);
//	freopen("3.txt", "r", stdin);
//	freopen("1.txt", "w", stdout);
	
	scanf("%s", a + 1), n = strlen(a + 1);
	a[0] = a[n + 1] = '.';
	f[0][0][1] = f[0][0][0] = 1;

	flag = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] == '?') {
			flag = 1;
			break;
		}
	if (!flag) {
		printf("%d\n", check());
		/// ?
		return 0;
	}
	
	for (int i = 1; i <= n; i++)
		switch (a[i]) {
			case '1':
				f[i][0][0] = f[i - 1][1][0];
				f[i][0][1] = f[i - 1][0][0];
				break;
			case '2':
				f[i][0][1] = f[i - 1][1][0];
				break;
			case '0':
				f[i][0][0] = f[i - 1][0][0];
				break;
			case '*':
				f[i][1][0] = (f[i - 1][0][1] + f[i - 1][1][1]) % p;
				f[i][1][1] = (f[i - 1][0][1] + f[i - 1][1][1]) % p;
				break;
			case '?':
				// 1
				(f[i][0][0] += f[i - 1][1][0]) %= p;
				(f[i][0][1] += f[i - 1][0][0]) %= p;
				// 2
				(f[i][0][1] += f[i - 1][1][0]) %= p;
				// 0
				(f[i][0][0] += f[i - 1][0][0]) %= p;
				// *
				(f[i][1][0] += f[i - 1][0][1] + f[i - 1][1][1]) %= p;
				(f[i][1][1] += f[i - 1][0][1] + f[i - 1][1][1]) %= p;
				break;
		}
		
//	for (int i = 1; i <= n; i++)
//		printf("%4d", f[i][0][0]);
//	puts("");
//	for (int i = 1; i <= n; i++)
//		printf("%4d", f[i][0][1]);
//	puts("");
//	for (int i = 1; i <= n; i++)
//		printf("%4d", f[i][1][0]);
//	puts("");
//	for (int i = 1; i <= n; i++)
//		printf("%4d", f[i][1][1]);
//	puts("");
	
	printf("%d\n", (f[n][0][0] + f[n][1][0]) % p);

	return 0;
}