#include<bits/stdc++.h>
using namespace std;
#define re register
int a[2010],b1[2010],b[2010],a1[2010];
int main()
{
	re int n,x=0,x1,n1,ans;
	scanf("%d",&n);ans=n;
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);a1[i]=a[i];
	}
	sort(a1+1,a1+n+1);
	n1=unique(a1+1,a1+n+1)-a1-1;
	for(re int i=1;i<=n;i++)a[i]=lower_bound(a1+1,a1+n1+1,a[i])-a1;
	for(re int i=1;i<=n;i++)
	{
		b[a[i]]++;
		if(b[a[i]]==2)x++;
	}
	if(x==0){puts("0");return 0;}
	for(re int i=1;i<=n;i++)
	{
		for(re int j=1;j<=n1;j++)
		b1[j]=b[j];
		x1=x;
		for(re int j=i;j<=n;j++)
		{
			b1[a[j]]--;
			if(b1[a[j]]==1)x1--;
			if(x1==0&&j-i+1<ans)ans=j-i+1;
		}
	}
	printf("%d\n",ans);
}