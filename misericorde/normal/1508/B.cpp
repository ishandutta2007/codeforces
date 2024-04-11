#include <bits/stdc++.h>

using ll = long long;
int n,f[1000005];
ll k;

int get(ll x,int y) {
	if (y > 61) return 0;
	return (x >> y) & 1;
}

void solve() {
	scanf("%d%lld",&n,&k); 
	assert((1ll << 60) > ((int)1e18));
	if (n <= 60 && ( (1ll << (n - 1)) < k) ) { puts("-1"); return ; }
	k --;
	for (int i = 1; i < n; ++ i) 
		f[i] = get(k,n - i - 1);
	f[n] = 0;
	int l = 1, cur = 0;
	for (int i = 1; i <= n; ++ i) {
		if (f[i] == 0) {
			for (int j = l + cur; j >= l; j --) printf("%d ",j);
			l = l + cur + 1; cur = 0;
		} else cur ++;
	} puts("");
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	
	return 0;
}