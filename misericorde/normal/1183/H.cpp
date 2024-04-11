#include <bits/stdc++.h>
 
long long f[105][27][105]={0},k1;
int n;
char s[105];
//lgoj
int main() {
	scanf("%d%I64d",&n,&k1);
	scanf("%s",s+1);
	f[0][26][0]=1;
	for (int i=1;i<=n;++i) {
		int now=0;
		for (int k=0;k<=i;++k) {
			for (int j=0;j<=26;++j) {
				if (j!=s[i]-'a') f[i][j][k]=std::min(k1,f[i][j][k]+f[i-1][j][k]);
			}for (int j=0;j<=26;++j) {
				f[i][s[i]-'a'][k]=std::min(k1,f[i][s[i]-'a'][k]+f[i-1][j][k-1]);
			}for (int j=0;j<=26;++j) now+=f[i][j][k];
		//	printf("%d ",now);
		}//printf("\n");
	}long long ans=0;
	for (int i=n;i>=0;i--) {
		long long now=0;
		for (int j=0;j<=26;++j) now+=f[n][j][i];
	//	printf("%d ",now);
		ans+=(n-i)*std::min(now,k1); k1-=now;
		if (k1<=0) break;
	}if (k1>0) {printf("-1");}
	else std::cout<<ans;
	return 0;
}