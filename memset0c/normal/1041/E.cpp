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

const int maxn = 1010;

int n, tot, top, maxx;
int a[maxn], b[maxn], u[maxn], v[maxn], stk[maxn];
bool flag[maxn];

bool cmp(int x, int y) {
	return x > y;
}

void addedge(int x, int y) {
	tot++;
	u[tot] = x, v[tot] = y;
}

int main() {
//	freopen("E.in", "r", stdin);
//	freopen("E.out", "w", stdout);

	n = read();
	for (int i = 1; i < n; i++) {
		a[i] = read(), b[i] = read();
		if (a[i] > b[i])
			swap(a[i], b[i]);
	}
	for (int i = 1; i < n; i++)
		if (b[i] != n) {
			printf("NO\n");
			return 0;
		}
	for (int i = 1; i < n; i++)
		flag[a[i]] = 1;
	for (int i = 1; i < n; i++)
		if (!flag[i])
			stk[++top] = i;
			
	sort(a + 1, a + n + 1, cmp);
	
	maxx = n;
	for (int i = 2, last = 1; i <= n; i++)
		if (a[i] ^ a[i - 1]) {
			int j = i - last - 1;
			if (top < j) {
				printf("NO\n");
				return 0;
			}
			for (int k = 1; k <= j; k++) {
				if (stk[top] > a[i-1]) {
					printf("NO\n");
					return 0;
				}
				addedge(maxx, stk[top]),
				maxx = stk[top--];
			}
			addedge(maxx, a[i - 1]);
			maxx = a[i - 1];
			last = i;
		}
		
	printf("YES\n");
	for (int i = 1; i < n; i++)
		printf("%d %d\n", u[i], v[i]);
		
	return 0;
}