#include <bits/stdc++.h>

const int maxn = 6e5 + 222;

int n,c[10],l[10],a[maxn];
char s[10][maxn];

void solve(int x,int y,int z,int t) {
	assert(l[x] == 2 * n);
	if (l[y] < l[z]) std::swap(y,z);
	for (int i = l[y] + 1; i <= 2 * n; ++ i) a[++t] = s[y][i] - '0';
	assert(t <= 3 * n);
	for (int i = 1; i <= 3 * n; ++ i) printf("%d",a[i]);
	puts("");
}

int find() {
	int cnt[2];
	cnt[0] = cnt[1] = 0;
	for (int i = 1; i <= 3; ++ i) cnt[c[i]] ++;
	if (cnt[0] >= 2) return 0;
	return 1;
}

void solve() {
	scanf("%d%s%s%s",&n,s[1] + 1, s[2] + 1, s[3] + 1);
	l[1] = l[2] = l[3] = 0;
	for (int i = 1; i <= 3 * n; ++ i) a[i] = 0;
	for (int i = 1; i <= 3 * n; ++ i) {
		for (int j = 1; j <= 3; ++ j) {
			c[j] = s[j][l[j] + 1] - '0';
		//	printf(">%d\n",c[j]);
		}
		int w = find();
		a[i] = w;
	//	printf("<%d>\n",w);
		for (int j = 1; j <= 3; ++ j) if (c[j] == w) l[j] ++;
		for (int j = 1; j <= 3; ++ j) if (l[j] == 2 * n) {
			if (j == 1) solve(1,2,3,i);
			if (j == 2) solve(2,1,3,i);
			if (j == 3) solve(3,1,2,i);
			return ;
		}
	}
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}