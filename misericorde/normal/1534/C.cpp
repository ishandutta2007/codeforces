#include <bits/stdc++.h>

const int maxn = 1e6 + 222;
using ll = long long;
const int mod = 1e9 + 7;

int fa[maxn],n,u[maxn],v[maxn],x;

int getf(int x) { return fa[x] ? fa[x] = getf(fa[x]) : x; }
void merge(int x,int y)  {
	x = getf(x);
	y = getf(y);
	if (x == y) return ;
	fa[y] = x;
}

void solve() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i) {
		fa[i] = 0;
		scanf("%d",&x);
		u[x] = i;
	} for (int i = 1; i <= n; ++ i) {
		scanf("%d",&x);
		v[x] = i;
	} for (int i = 1; i <= n; ++ i)
	merge(u[i],v[i]);
	int ans = 1;
	for (int i = 1; i <= n; ++ i)
		if (getf(i) == i) ans = (ll) ans * 2 % mod;
	printf("%d\n",ans);
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}