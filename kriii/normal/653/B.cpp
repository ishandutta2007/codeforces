#include <stdio.h>

int n,q; int d[6][6],c[10][6];

int main()
{
	for (int i=0;i<6;i++) for (int j=0;j<6;j++) d[i][j] = -1;
	scanf ("%d %d",&n,&q); while (q--){
		char s[10];
		scanf ("%s",s);
		int i = s[0] - 'a', j = s[1] - 'a';
		scanf ("%s",s);
		d[i][j] = s[0] - 'a';
	}

	c[1][0] = 1;
	for (int l=2;l<=n;l++){
		for (int i=0;i<6;i++) for (int j=0;j<6;j++) if (d[i][j] != -1){
			c[l][i] += c[l-1][d[i][j]];
		}
	}

	int ans = 0;
	for (int i=0;i<6;i++) ans += c[n][i];
	printf ("%d\n",ans);

	return 0;
}