#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
using namespace std;

const int maxn = 2e5 + 10;
int fa[maxn << 1],siz[maxn << 1];
void init(int n) {
	for(int i = 1; i <= n; ++i) fa[i] = i, siz[i] = 0;
	for(int i = n + 1; i <= n * 2; ++i) fa[i] = i, siz[i] = 1;
}
int get(int x) {
	return x == fa[x] ? x : fa[x] = get(fa[x]);
}
void unionn(int x, int y) {
	int fx = get(x), fy = get(y);
	if(fx == fy) return;
	fa[fy] = fx; siz[fx] += siz[fy]; siz[fy] = 0;
}

int t,n,m;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		init(n);
		while(m--) {
			int i,j; char s[30];
			scanf("%d%d%s", &i, &j, s);
			if(s[0] == 'i') unionn(i, j + n), unionn(i + n, j);
			else unionn(i, j), unionn(i + n, j + n);
		}
		bool fl = 1;
		for(int i = 1; i <= n && fl; ++i)
			if(get(i) == get(i + n)) fl = 0;
		if(fl) {
			int ans = 0;
			for(int i = 1; i <= n; ++i) {
				int f1 = get(i), f2 = get(i + n);
				ans += max(siz[f1], siz[f2]);
				siz[f1] = siz[f2] = 0;
			}
			printf("%d\n", ans);
		}
		else printf("-1\n");
	}
	return 0;
}