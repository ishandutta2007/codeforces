#include <bits/stdc++.h>

int n,m;
char s[1005][1005];

int check(int x) {
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			if (s[i][j] == '.') continue;
			int c = (s[i][j] == 'R');
			if (c != (i + j + x) % 2) return 0;
		}
	} puts("YES");
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			if ( (i + j + x) % 2 ) printf("R");
			else printf("W");
		} puts("");
	} return 1;
}

void solve() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++ i) 
		scanf("%s",s[i] + 1);
	for (int i = 0; i <= 1; ++ i) {
		if (check(i)) return ;
	} puts("NO"); 
	return ;
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}