#include <bits/stdc++.h>

int G[600][600],n,m,t;

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
	for (int j=1;j<=m;++j)
	scanf("%d",&G[i][j]);
	for (int i=1;i<=n;++i)
	for (int j=1;j<=m;++j)
	{scanf("%d",&t);G[i][j]^=t;}
	for (int i=1;i<=n;++i) {
		for (int j=1;j<=m;++j) {
			if (G[i][j]) {
				int k=j+1;
				for (;k<=m;++k) if (G[i][k]) break;
				if (!G[i][k]) {printf("NO\n");return 0;}
				int l=i+1;
				for (;l<=m;++l) if (G[l][k]) break;
				if (!G[l][k]) {printf("NO\n");return 0;}
			//	if (!G[l][j]) {printf("NO\n");return 0;}
				G[i][j]=G[i][k]=G[l][k]=0;G[l][j]^=1;
			}
		}
	}printf("YES\n");
	return 0;
}