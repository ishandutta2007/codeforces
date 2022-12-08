#include <stdio.h>

int f[1000001],g[1000001],s[10][1000001];

int main()
{
	for (int i=1;i<=9;i++) f[i] = g[i] = i;
	for (int i=10;i<=1000000;i++){
		int u = i / 10, v = i % 10;
		if (!v) v = 1;
		f[i] = f[u] * v;
	}
	for (int i=10;i<=1000000;i++){
		g[i] = g[f[i]];
	}
	for (int i=1;i<=1000000;i++){
		s[g[i]][i] = 1;
		for (int k=1;k<=9;k++) s[k][i] += s[k][i-1];
	}

	int Q; scanf ("%d",&Q); while (Q--){
		int l,r,k;
		scanf ("%d %d %d",&l,&r,&k); l--;
		printf ("%d\n",s[k][r]-s[k][l]);
	}

	return 0;
}