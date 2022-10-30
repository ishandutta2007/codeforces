#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],b[1000005],pos[1000005];
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			if(a[i]==a[i-1]) pos[i]=pos[i-1];else pos[i]=i;
		}
		for(int l,r,x;m--;)
		{
			scanf("%d%d%d",&l,&r,&x);
			if(a[r]==x) {if(pos[r]<=l) puts("-1");else printf("%d\n",pos[r]-1);}else printf("%d\n",r);
		}
	}
	return 0;
}