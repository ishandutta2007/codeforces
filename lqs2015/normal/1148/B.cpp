#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,m,k,ta,tb,s,t,a[222222],b[222222],mx;
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
	if (k>=min(n,m)) 
	{
		printf("-1\n");
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
	}
	mx=-1e9;
	for (int i=1;i<=n && i<=k+1;i++)
	{
		t=lower_bound(b+1,b+m+1,a[i]+ta)-b;
		t+=(k-i+1);
		if (t>m)
		{
			printf("-1\n");
			return 0;
		}
		mx=max(mx,b[t]+tb);
	}
	printf("%d\n",mx);
	return Accepted;
}