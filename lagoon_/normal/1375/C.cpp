#include<bits/stdc++.h>
#define re register
int a[310310];
int main()
{
	re int n,t,m,x;
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%d",&n);
		for(re int i=1;i<=n;i++)scanf("%d",&a[i]);
		if(a[1]<a[n])puts("YES");
		else puts("NO");
	}
}