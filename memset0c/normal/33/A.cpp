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
const int inf = 1000000000;
int n, m, k, ans, a[maxn];

int main() {
	
    n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i++)
		a[i] = inf;
    for (int i = 1, x, c; i <= n; i++) {
        x = read(), c = read();
        a[x] = min(a[x], c);
    }
    for (int i = 1; i <= m; i++)
		ans += a[i];
	printf("%d",min(ans,k));

	return 0;

}