#include <bits/stdc++.h>

int f[105][27][105]={0},n,k;
char s[105];

int main() {
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	f[0][26][0]=1;
	for (int i=1;i<=n;++i) {
		int now=0;
		for (int k=0;k<=i;++k) {
			now=0;
			for (int j=0;j<=26;++j) {
				if (j!=s[i]-'a') f[i][j][k]=std::min(100,f[i][j][k]+f[i-1][j][k]);
			}for (int j=0;j<=26;++j) {
				f[i][s[i]-'a'][k]=std::min(100,f[i][s[i]-'a'][k]+f[i-1][j][k-1]);
			}for (int j=0;j<=26;++j) now+=f[i][j][k];
		//	printf("%d ",now);
		}//printf("\n");
	}int ans=0;
	for (int i=n;i>=0;i--) {
		int now=0;
		for (int j=0;j<=26;++j) now+=f[n][j][i];
	//	printf("%d ",now);
		ans+=(n-i)*std::min(now,k); k-=now;
		if (k<=0) break;
	}if (k>0) {printf("-1");}
	else printf("%d",ans);
	return 0;
}