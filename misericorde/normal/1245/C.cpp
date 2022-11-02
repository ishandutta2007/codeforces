#include <bits/stdc++.h>
const int mod=1e9+7;
char s[1000005];
int dp[100005]={0};
int main(){
	scanf("%s",s+1);
	int n=std::strlen(s+1);
	for(int i=1;i<=n;++i){if (s[i]=='m'||s[i]=='w'){printf("0");return 0;}}
	dp[0]=1;
	for(int i=1;i<=n;++i){
		dp[i]=dp[i-1];
		if (s[i]=='u'&&s[i-1]=='u')dp[i]=(dp[i]+dp[i-2])%mod;
		if (s[i]=='n'&&s[i-1]=='n')dp[i]=(dp[i]+dp[i-2])%mod;
	}printf("%d",dp[n]);
	return 0;
}