#include<bits/stdc++.h>
#define int long long
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=100000+5,Inf=(1LL<<60)-1;
int a[MaxN],b[MaxN],c[MaxN];
int Sum1[MaxN],Min1[MaxN],Rec1[MaxN];
int Sum2[MaxN],Min2[MaxN],Rec2[MaxN];
signed main()
{
	register int t;
	scanf("%lld",&t);
	while(t--)
	{
		register int n;
		scanf("%lld",&n);
		register int x=0,y=0;
		rep(i,1,n)
		{
			scanf("%lld",&a[i]);
			if(i&1)
				b[++x]=a[i];
			else
				c[++y]=a[i];
		}
		rep(i,0,max(x,y)+2)
			Rec1[i]=Rec2[i]=Inf;
		rep(i,0,x)
		{
			Sum1[i]=0;
			Min1[i]=Inf;
		}
		rep(i,1,x)
		{
			Sum1[i]=Sum1[i-1]+b[i];
			Min1[i]=min(Min1[i-1],b[i]);
		}
		rep(i,1,x)
			Rec1[i]=Sum1[i]+Min1[i]*(n-i);
		rep(i,0,y)
		{
			Sum2[i]=0;
			Min2[i]=Inf;
		}
		rep(i,1,y)
		{
			Sum2[i]=Sum2[i-1]+c[i];
			Min2[i]=min(Min2[i-1],c[i]);
		}
		rep(i,1,y)
			Rec2[i]=Sum2[i]+Min2[i]*(n-i);
		register int Ans=Inf;
		rep(i,1,max(x,y))
			Ans=min(Ans,Rec1[i]+Rec2[i]);
		rep(i,1,max(x,y))
			Ans=min(Ans,Rec1[i+1]+Rec2[i]);
		printf("%lld\n",Ans);
	}
	return 0;
}