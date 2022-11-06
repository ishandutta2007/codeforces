#include<bits/stdc++.h>
#define re register
std::vector<int>a[1001000];
int len[1001000],s[1001000];
bool bo[1001000];
int main()
{
	re int n,x,p;
	scanf("%d",&n);p=n;
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&len[i]);a[i].push_back(0);
		for(re int j=1;j<=len[i];j++)scanf("%d",&x),a[i].push_back(x);
		re int ii=2;
		for(;ii<=len[i];ii++)if(a[i][ii]>a[i][ii-1])break;
		if(ii<=len[i])p--;else bo[i]=1;
	}
	re long long ans=1ll*n*n-1ll*p*p;
	for(re int i=1;i<=n;i++)if(bo[i])s[a[i][len[i]]]++;
	for(re int i=1;i<=1e6;i++)s[i]+=s[i-1];
	for(re int i=1;i<=n;i++)if(bo[i])ans+=s[a[i][1]-1];
	printf("%lld\n",ans);
}