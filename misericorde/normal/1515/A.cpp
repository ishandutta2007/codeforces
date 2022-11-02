#include <bits/stdc++.h>

int n,x,a[10005];

void solve() {
	scanf("%d%d",&n,&x);
	for (int i = 1; i <= n; ++ i) scanf("%d",&a[i]);
	for (int i = 1; i <= 100; ++ i) {
		std::random_shuffle(a+1,a+n+1);
		int s = 0;
		int flag = 1;
		for (int j = 1; j <= n; ++ j) {
			s += a[j];
			if (s == x) { flag = 0; break; }
		} if (flag) {
			puts("YES");
			for (int j = 1; j <= n; ++ j) printf("%d ",a[j]); puts("");
			return ;
		}
	} puts("NO");
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}