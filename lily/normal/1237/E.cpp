#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

#define MOD 998244353

int n;
bool vis[1231231];
queue <int> q;
int main() {
	read(n);
	q.push(1); vis[1] = 1;
	q.push(2); vis[2] = 1;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		if (x == n) {
			puts("1"); return 0;
		}
		if (x % 2 == 0 && 2 * x <= n && !vis[2 * x + 1]) {
			vis[2 * x + 1] = 1;
			q.push(2 * x + 1);
		}
		if (vis[x + 1] && 2 * x + 2 <= n && !vis[2 * x + 2]) {
			vis[2 * x + 2] = 1;
			q.push(2 * x + 2);
		}
	}
	puts("0");
}