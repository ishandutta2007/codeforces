#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=100000+5;
int a[MaxN];
int main()
{
	register int T;
	scanf("%d",&T);
	register int n,u,v;
	while(T--)
	{
		scanf("%d%d%d",&n,&u,&v);
		register bool flag=true,ok=false;
		rep(i,1,n)
		{
			scanf("%d",&a[i]);
			flag&=(a[i]==a[1]);
			ok|=((i!=1)&&(abs(a[i]-a[i-1])>=2));
		}
		if(ok)
			printf("%d\n",0);
		else if(flag)
			printf("%d\n",v+min(u,v));
		else
			printf("%d\n",min(u,v));
	}
	return 0;
}