#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=100000+5;
int a[MaxN];
bool c[MaxN];
int main()
{
	register int T;
	scanf("%d",&T);
	register int n,k;
	while(T--)
	{
		scanf("%d%d",&n,&k);
		rep(i,0,n+1)
			c[i]=false;
		rep(i,1,n)
		{
			scanf("%d",&a[i]);
			if(a[i]<=n)
				c[a[i]]=true;
		}
		sort(a+1,a+n+1);
		register int Max=a[n],Mex=0,val;
		rep(i,0,n)
		{
			if(c[i])
				++Mex;
			else
				break;
		}
		val=(Max+Mex+1)>>1;
		register int cnt=0;
		if(k==0)
			cnt=0;
		else if(val>Max)
			cnt=k;
		else if(a[(lower_bound(a+1,a+n+1,val)-a)]==val)
			cnt=0;
		else
			cnt=1;
		printf("%d\n",n+cnt);
	}
	return 0;
}