#include<bits/stdc++.h>
#define int long long
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=100000+5;
int a[MaxN],b[MaxN];
signed main()
{
	register int T;
	scanf("%lld",&T);
	register int n;
	while(T--)
	{
		register int x,y,u=0,v=0;
		scanf("%lld",&n);
		rep(i,1,n<<1)
		{
			scanf("%lld%lld",&x,&y);
			if(x==0)
				b[++v]=abs(y);
			else
				a[++u]=abs(x);
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		register double Ans=0.0;
		rep(i,1,n)
			Ans+=sqrt(a[i]*a[i]+b[i]*b[i]);
		printf("%.16Lf\n",Ans);
	}
	return 0;
}