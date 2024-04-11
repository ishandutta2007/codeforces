#include <bits/stdc++.h>

int n,m,b[105][105],fr[105],re[105],A[105][105];

void solve() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j) 
			scanf("%d",&b[i][j]);
		fr[i] = 1; re[i] = m;
		std::sort(b[i]+1,b[i]+m+1);
	}
	for (int i = 1; i <= m; ++ i) {
		int min = 1;
		for (int j = 1; j <= n; ++ j) if (b[j][fr[j]] < b[min][fr[min]]) min = j;
	//	printf(">%d(%d)\n",min,b[min][fr[min]]);
		A[i][min] = b[min][fr[min]];
		fr[min] ++;
		for (int j = 1; j <= n; ++ j) {
			if (j == min) continue;
			A[i][j] = b[j][re[j]];
			re[j] --;
		}
	} for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j)  {
			printf("%d ",A[j][i]);
		} puts("");
	}
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}