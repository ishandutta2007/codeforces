#include<bits/stdc++.h>
#define re register
int a[200010],b[20010];
int main()
{
	re int t,n,m,ans=1;
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%d",&n);
		for(re int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(re int i=1;i<=n;i++)scanf("%d",&b[i]);
		std::sort(a+1,a+n+1);
		std::sort(b+1,b+n+1);
		for(re int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
		for(re int i=1;i<=n;i++)printf("%d ",b[i]);puts("");
	}
}