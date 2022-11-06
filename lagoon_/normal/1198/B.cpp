#include<bits/stdc++.h>
using namespace std;
#define re register
#define ui unsigned int
#define ull unsigned long long
int tp[200100],p[200100],x[200100],a[200100];
int main()
{
	re int n,q,x1=0;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}scanf("%d",&q);
	for(re int i=1;i<=q;i++)
	{
		scanf("%d",&tp[i]);
		if(tp[i]==1)scanf("%d",&p[i]);
		scanf("%d",&x[i]);
	}
	for(re int i=q;i;i--)
	{
		if(tp[i]==2&&x[i]>x1)x1=x[i];
		else if(x1>x[i])x[i]=x1;
	}
	for(re int i=1;i<=n;i++)if(a[i]<x1)a[i]=x1;
	for(re int i=1;i<=q;i++)if(tp[i]==1)a[p[i]]=x[i];
	for(re int i=1;i<=n;i++)printf("%d ",a[i]);
}