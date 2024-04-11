#include <bits/stdc++.h>
//lgjudger
char s[1<<20];
bool vis[1<<21]={0};int dp[1<<21]={0};
int main(){
	int ans=0;
	scanf("%s",s+1);int n=std::strlen(s+1);
	for(int i=1;i<=n;++i){
		int tmp=0;
		for (int j=i;j>=1;j--){
			if (tmp&(1<<(s[j]-'a')))break;
			tmp|=(1<<(s[j]-'a'));vis[tmp]=1; 
		}vis[tmp]=1;
	}for(int i=0;i<(1<<20);++i){
		for(int j=0;j<20;++j){if ((i|(1<<j))==i)dp[i]=std::max(dp[i],dp[i^(1<<j)]);}
		if (vis[i])dp[i]=std::max(dp[i],__builtin_popcount(i));
	}for(int i=0;i<(1<<20);++i){
		int U=(1<<20)-1;
		if (vis[i])ans=std::max(ans,__builtin_popcount(i)+dp[U^i]);
	}printf("%d",ans);
	return 0;
}