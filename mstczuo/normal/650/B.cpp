# include <iostream>
# include <cstdio>
# include <cstring>
# include <cstring>
# include <algorithm>
using namespace std;

typedef long long ll;

const int maxn = 500010;

char dir[maxn];

int n, a, b, T;

int pre[maxn], suf[maxn];

int ans = 0;

int main() {
	scanf("%d%d%d%d", &n, &a, &b, &T); 
	scanf("%s", dir);
	if(dir[0] == 'w') {
		if(T < b + 1) { puts("0"); return 0; }
		T -= b + 1; ans = 1;
	} else {
		if(T < 1) { puts("0"); return 0; }
		T -= 1; ans = 1;
	}
	for(int i = 1; i <= n - 1; ++i) {
		pre[i] = pre[i - 1] + a + (dir[i] == 'w' ? b + 1 : 1);
		if(pre[i] <= T) {
			ans = max(ans, 1 + i);
		}
	}
	for(int i = n - 1; i >= 1; --i) {
		suf[i] = suf[i + 1] + a + (dir[i] == 'w' ? b + 1 : 1);
		if(suf[i] <= T) {
			ans = max(ans, 1 + (n - i));
		}
	}
	if(ans == n) { printf("%d\n", n); return 0; }
	for(int i = 1, j = 2; i < n; ++i) {
		while(j <= i) ++j;
		while(j < n && min(i, n - j) * a + pre[i] + suf[j] > T) ++j;
		if(j >= n) break;
		ans = max(ans, i + 1 + (n - j));
	}
	printf("%d\n", ans);
	return 0;
}