#include<bits/stdc++.h>
#define re register
int a[200010],b[1010];
int main()
{
	re int n,m,ans=1;
	scanf("%d%d",&n,&m);
	if(n>m){puts("0");return 0;}
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(re int j=1;j<i;j++)ans=1ll*ans*abs(a[i]-a[j])%m;
	}
	printf("%d\n",ans);
}