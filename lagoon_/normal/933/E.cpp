#include<bits/stdc++.h>
using namespace std;
#define re register
#define dmax(a,b) ((a)>(b)?(a):(b))
#define dmin(a,b) ((a)<(b)?(a):(b))
long long f[300100];
int p[300100],v[300100],ans[300100],m,q[300100];
void dd(re int a)
{
	re int x=dmin(p[a],p[a+1]);
	p[a]-=x;p[a+1]-=x;
	if(x)ans[++m]=a;
}
int main()
{
	re int n,cnt=0;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		re long long x=f[dmax(i-3,0)]+dmax(p[i],p[i-1]),y=f[dmax(i-2,0)]+p[i];
		if(x>y)f[i]=y,v[i]=1;
		else f[i]=x;
	}
	re int n1;
	if(f[n-1]<=f[n])n1=n-1;else n1=n;
	for(;n1>0;n1-=3-v[n1])q[++cnt]=n1;
	for(re int i=cnt;i;i--)
	{
		if(!v[q[i]])dd(q[i]-1);
		dd(q[i]);
		dd(q[i+1]+1);
	}
	printf("%d\n",m);
	for(re int i=1;i<=m;i++)printf("%d\n",ans[i]);
}