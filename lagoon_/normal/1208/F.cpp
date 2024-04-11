#include<bits/stdc++.h>
using namespace std;
#define re register
struct par
{
	int x,y;
	void upd(re int a)
	{
		if(a>x)y=x,x=a;
		else if(a>y)y=a;
	}
}f[(1<<21)+11];
int a[1001000];
int main()
{
	re int n,ans=0;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[a[i]].upd(i);
	}
	for(re int i=0;i<=20;i++)
	{
		for(re int i1=1;i1<(1<<21);i1++)
		if(i1&(1<<i)){
			f[i1-(1<<i)].upd(f[i1].x);
			f[i1-(1<<i)].upd(f[i1].y);
		}
	}
	for(re int i=n-2;i;i--)
	{
		re int num=0;
		for(re int i1=20;i1>=0;i1--)if(!(a[i]&(1<<i1)))
		{
			if(f[num|(1<<i1)].y>i)num|=(1<<i1);
		}
		if((num|a[i])>ans)ans=num|a[i];
	}
	printf("%d\n",ans);
}