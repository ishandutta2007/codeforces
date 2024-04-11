#include <bits/stdc++.h>

int n,vis[105]={0},a[105],b[105];
char s[105];

int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int i=1;i<=n;++i){
		scanf("%d%d",&a[i],&b[i]);
		vis[i]=s[i]-'0';
	}int ans=0,tmp=0;
	for (int i=1;i<=n;++i)tmp+=vis[i];
	ans=std::max(ans,tmp);
	for (int i=1;i<=100000;++i){
		for (int j=1;j<=n;++j)
			if ((i>=b[j])&&((i-b[j])%a[j]==0))vis[j]^=1;
		tmp=0;
		for (int j=1;j<=n;++j)tmp+=vis[j];
		ans=std::max(ans,tmp);
	}printf("%d",ans);
	return 0;
}