#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define M 1000005
int n,cnt,tp,a[N];
struct Answer {int x1,x2;}ans[M];
void f(int x1,int x2)
{
	if(a[x1]>a[x2]) swap(x1,x2);
	ans[++tp]=(Answer) {x1,x2};
	a[x2]-=a[x1];a[x1]*=2;
}
void slv(int x1,int x2,int x3)
{
	while(1)
	{
		if(a[x1]>a[x2]) swap(x1,x2);
		if(a[x1]>a[x3]) swap(x1,x3);
		if(a[x2]>a[x3]) swap(x2,x3);
		if(!a[x1]) break;int t=a[x2]/a[x1];
		for(int i=0;1<<i<=t;++i)
			f(x1,(t>>i&1?x2:x3)); 
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1,x1=0,x2=0,x3=0;i<=n;++i)
	{
		if(a[i]>0)
		{
			if(!x1) x1=i;else if(!x2) x2=i;
			else if(!x3) x3=i;++cnt;
		}
		if(x1 && x2 && x3)
		{
			slv(x1,x2,x3);if(!a[x1]) x1=0;
			if(!a[x2]) x2=0;if(!a[x3]) x3=0;
		}
	}if(cnt<2) {puts("-1");return 0;}
	printf("%d\n",tp);
	for(int i=1;i<=tp;++i)
		printf("%d %d\n",ans[i].x1,ans[i].x2);
	return 0;
}