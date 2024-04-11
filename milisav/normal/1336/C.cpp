#include<bits/stdc++.h>
#define maxn 5000
using namespace std;
long long mod=998244353;
int n,m;
char s[maxn];
char t[maxn];
long long dp[maxn][maxn][2];
void print(int g) {
	for(int i=0;i<m;i++) {
		for(int j=i;j<m;j++) printf("%d %d %lld\n",i,j,dp[i][j][g]);
	}
}
int main() {
	scanf("%s",s);
	scanf("%s",t);
	n=strlen(s);
	m=strlen(t);
	for(int j=0;j<m;j++) {
		if(t[j]==s[0]) dp[j][j][0]=2;
	}
	int g=0;
	long long stp=2;
	long long ans=dp[0][m-1][g];
	for(int i=1;i<n;i++) {
		for(int j=0;j<m;j++) dp[j][m-1][g^1]=dp[j][m-1][g];
		for(int j=0;j+i<m;j++) {
			if(s[i]==t[j+i]) dp[j][j+i][g^1]=(dp[j][j+i][g^1]+dp[j][j+i-1][g])%mod;
			if(s[i]==t[j]) dp[j][j+i][g^1]=(dp[j][j+i][g^1]+dp[j+1][j+i][g])%mod;
		}
		for(int j=0;j<m;j++) {
			if(i+j<m) continue;
			if(s[i]==t[j]) {
				if(j!=m-1) dp[j][m-1][g^1]=(dp[j][m-1][g^1]+dp[j+1][m-1][g])%mod;
				else dp[j][m-1][g^1]=(dp[j][m-1][g^1]+stp)%mod;
			}
		}
		g^=1;
		ans=(ans+dp[0][m-1][g])%mod;
		//print(g);
		stp=(stp*2)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}